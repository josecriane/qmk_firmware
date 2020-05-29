#pragma once

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <util/delay.h>

#include "util.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern uint8_t mcp23018_status;
#define I2C_TIMEOUT 100
extern uint8_t mcp23018_input_pin_mask;
extern bool i2c_initialized;

void init_mcp23018(void);

enum layers {
    DVORAK, // default layer
    MOD,
    ARR,
    GAME,
    M_DVORAK, // default mac layer
    M_MOD,
    M_ARR,
    CH,
};

enum macros_custom {
	_A_TILD = SAFE_RANGE,
	_O_TILD,
	_E_TILD,
	_U_TILD,
	_I_TILD,
	_ENHE,
	_A_TILD_M,
	_O_TILD_M,
	_E_TILD_M,
	_U_TILD_M,
	_I_TILD_M,
	_ENHE_M,
};

#define LAYOUT_67manuform_pretty(                                        \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,L26,           R20,R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,L45,L46,           R40,R41,R42,R43,R44,R45,R46,  \
                L50,L51,L52,                   R51,R52,R53,              \
                            L53,L54,   R54,R50,                          \
                            L55,L56,   R56,R55 )                         \
                                                                         \
    /* matrix positions */                                               \
    {                                                                    \
     { R06, R05, R04, R03, R02, R01, R00, L00, L01, L02, L03, L04, L05, L06 }, \
     { R16, R15, R14, R13, R12, R11, R10, L10, L11, L12, L13, L14, L15, L16 }, \
     { R26, R25, R24, R23, R22, R21, R20, L20, L21, L22, L23, L24, L25, L26 }, \
     { R36, R35, R34, R33, R32, R31, R30, L30, L31, L32, L33, L34, L35, L36 }, \
     { R46, R45, R44, R43, R42, R41, R40, L40, L41, L42, L43, L44, L45, L46 }, \
     { R53, R52, R51, R50, R54, R55, R56, L50, L51, L52, L53, L54, L55, L56 }, \
    }
