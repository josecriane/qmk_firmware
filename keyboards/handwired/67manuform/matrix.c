/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2017 Erin Call <hello@erincall.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "67manuform.h"
#include "i2c_master.h"
#include "timer.h"


/* Set 0 if debouncing isn't needed */

#ifndef DEBOUNCE
#   define DEBOUNCE 5
#endif

#if (DEBOUNCE > 0)
    static uint16_t debouncing_time;
    static bool debouncing = false;
#endif

#ifdef MATRIX_MASKED
    extern const matrix_row_t matrix_mask[];
#endif

static const uint8_t onboard_row_pins[MATRIX_ROWS] = MATRIX_ONBOARD_ROW_PINS;
static const uint8_t onboard_col_pins[MATRIX_COLS] = MATRIX_ONBOARD_COL_PINS;
static const bool col_expanded[MATRIX_COLS] = COL_EXPANDED;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static const uint8_t expander_col_pins[MATRIX_COLS] = MATRIX_EXPANDER_COL_PINS;
static void init_cols(void);
static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
static void unselect_rows(void);
static void select_row(uint8_t row);
static void unselect_row(uint8_t row);

static uint8_t expander_reset_loop;
uint8_t mcp23018_status;
uint8_t mcp23018_input_pin_mask;
bool i2c_initialized = false;

#define ROW_SHIFTER ((matrix_row_t)1)

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

__attribute__ ((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }

inline uint8_t matrix_cols(void) { return MATRIX_COLS; }

void matrix_init(void)
{
    init_mcp23018();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

    matrix_init_quantum();
}

uint8_t matrix_scan(void)
{
    if (mcp23018_status) { // if there was an error
        if (++expander_reset_loop == 0) {
            // since expander_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            print("trying to reset expander\n");
            init_mcp23018();
            if (mcp23018_status) {
                print("left side not responding\n");
            } else {
                print("left side attached\n");
            }
        }
    }

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
#       if (DEBOUNCE > 0)
            bool matrix_changed = read_cols_on_row(matrix_debouncing, current_row);

            if (matrix_changed) {
                debouncing = true;
                debouncing_time = timer_read();
            }
#       else
            read_cols_on_row(matrix, current_row);
#       endif
    }

#   if (DEBOUNCE > 0)
        if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCE)) {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
            debouncing = false;
        }
#   endif

    matrix_scan_quantum();
    return 1;
}

bool matrix_is_modified(void) // deprecated and evidently not called.
{
#if (DEBOUNCE > 0)
    if (debouncing) return false;
#endif
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & (ROW_SHIFTER << col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
#ifdef MATRIX_MASKED
    return matrix[row] & matrix_mask[row];
#else
    return matrix[row];
#endif
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

static void init_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (! col_expanded[x]) {
            uint8_t pin = onboard_col_pins[x];
            _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
            _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
        }
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);

    // Read columns from expander, unless it's in an error state
    if (! mcp23018_status) {
        mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);           if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(EXPANDER_COL_REGISTER, I2C_TIMEOUT);    if (mcp23018_status) goto out;
        mcp23018_status = i2c_start(I2C_ADDR_READ, I2C_TIMEOUT);            if (mcp23018_status) goto out;

        current_matrix[current_row] |= (~i2c_read_nack(I2C_TIMEOUT)) & mcp23018_input_pin_mask;

        out:
            i2c_stop();
    }

    // Read columns from onboard pins
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        if (! col_expanded[col_index]) {
            uint8_t pin = onboard_col_pins[col_index];
            uint8_t pin_state = (_SFR_IO8(pin >> 4) & _BV(pin & 0xF));
            current_matrix[current_row] |= pin_state ? 0 : (ROW_SHIFTER << col_index);
        }
    }

    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

static void select_row(uint8_t row) {
    // select on expander, unless it's in an error state
    if (! mcp23018_status) {
        // set active row low  : 0
        // set other rows hi-Z : 1
        mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);           if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(EXPANDER_ROW_REGISTER, I2C_TIMEOUT);    if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(0xFF & ~(1<<row), I2C_TIMEOUT);         if (mcp23018_status) goto out;
    out:
        i2c_stop();
    }

    // select on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) |=  _BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) &= ~_BV(pin & 0xF); // LOW
}

static void unselect_row(uint8_t row)
{
    // No need to explicitly unselect expander pins--their I/O state is
    // set simultaneously, with a single bitmask sent to i2c_write. When
    // select_row selects a single pin, it implicitly unselects all the
    // other ones.

    // unselect on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // LOW
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        unselect_row(x);
    }
}

// 67Manuform Private functions
void init_mcp23018(void) {
    if (! i2c_initialized) {
        i2c_init();
        _delay_ms(1000);
    }

    if (! mcp23018_input_pin_mask) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (col_expanded[col]) {
                mcp23018_input_pin_mask |= (1 << expander_col_pins[col]);
            }
        }
    }

    /*
    Pin direction and pull-up depends on both the diode direction
    and on whether the column register is GPIOA or GPIOB
    +-------+---------------+
    | GPIOA | output, input |
    +-------+---------------+
    | GPIOB | input, output |
    +-------+---------------+
    */
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT); if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA, I2C_TIMEOUT);         if (mcp23018_status) goto out;
#if (EXPANDER_COL_REGISTER == GPIOA)
        mcp23018_status = i2c_write(mcp23018_input_pin_mask, I2C_TIMEOUT); if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(0, I2C_TIMEOUT);                       if (mcp23018_status) goto out;
#elif (EXPANDER_COL_REGISTER == GPIOB)
        mcp23018_status = i2c_write(0, I2C_TIMEOUT);                       if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(mcp23018_input_pin_mask); if (mcp23018_status) goto out;
#endif
    i2c_stop();

    // set pull-up
    // - unused  : off : 0
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);              if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA, I2C_TIMEOUT);                       if (mcp23018_status) goto out;
#if (EXPANDER_COL_REGISTER == GPIOA)
        mcp23018_status = i2c_write(mcp23018_input_pin_mask, I2C_TIMEOUT); if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(0, I2C_TIMEOUT);                       if (mcp23018_status) goto out;
#elif (EXPANDER_COL_REGISTER == GPIOB)
        mcp23018_status = i2c_write(0, I2C_TIMEOUT);                       if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(mcp23018_input_pin_mask, I2C_TIMEOUT); if (mcp23018_status) goto out;
#endif

out:
    i2c_stop();
}
