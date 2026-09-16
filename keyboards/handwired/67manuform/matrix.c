// Copyright 2020 josecriane
// SPDX-License-Identifier: GPL-2.0-or-later

#include "gpio.h"
#include "matrix.h"
#include "mcp23018.h"
#include "debug.h"
#include "wait.h"

#define EXPANDER_ADDR 0x20
#define EXPANDER_COLS 7

static const pin_t row_pins[MATRIX_ROWS] = {F0, F1, F4, F5, F6, F7};
static const pin_t col_pins[MATRIX_COLS - EXPANDER_COLS] = {B0, B1, B2, B3, D2, D3, C6};

static uint8_t expander_errors = 0;

static void expander_config(void) {
    expander_errors += !mcp23018_set_config(EXPANDER_ADDR, mcp23018_PORTA, ALL_INPUT);
    expander_errors += !mcp23018_set_config(EXPANDER_ADDR, mcp23018_PORTB, ALL_OUTPUT);
}

static void expander_scan(void) {
    if (!expander_errors) {
        return;
    }

    static uint16_t reset_loop = 0;
    if (++reset_loop > 0x1FFF) {
        dprintf("trying to reset mcp23018\n");
        reset_loop      = 0;
        expander_errors = 0;
        expander_config();
    }
}

static void select_row(uint8_t row) {
    gpio_set_pin_output(row_pins[row]);
    gpio_write_pin_low(row_pins[row]);

    if (!expander_errors) {
        expander_errors += !mcp23018_set_output(EXPANDER_ADDR, mcp23018_PORTB, ~(1 << row));
    }
}

static void unselect_row(uint8_t row) {
    gpio_set_pin_input_high(row_pins[row]);
}

static matrix_row_t read_cols(void) {
    matrix_row_t cols = 0;

    if (!expander_errors) {
        uint8_t state = 0xFF;
        if (mcp23018_read_pins(EXPANDER_ADDR, mcp23018_PORTA, &state)) {
            cols |= (uint8_t)~state & ((1 << EXPANDER_COLS) - 1);
        } else {
            expander_errors++;
        }
    }

    for (uint8_t i = 0; i < MATRIX_COLS - EXPANDER_COLS; i++) {
        if (!gpio_read_pin(col_pins[i])) {
            cols |= (matrix_row_t)1 << (EXPANDER_COLS + i);
        }
    }

    return cols;
}

void matrix_init_custom(void) {
    mcp23018_init(EXPANDER_ADDR);
    expander_config();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        unselect_row(row);
    }
    for (uint8_t i = 0; i < MATRIX_COLS - EXPANDER_COLS; i++) {
        gpio_set_pin_input_high(col_pins[i]);
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    expander_scan();

    bool changed = false;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        select_row(row);
        wait_us(30);
        matrix_row_t cols = read_cols();
        unselect_row(row);

        if (current_matrix[row] != cols) {
            current_matrix[row] = cols;
            changed             = true;
        }
    }
    return changed;
}
