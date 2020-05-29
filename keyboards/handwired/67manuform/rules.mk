# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = halfkay

# Build Options
#   comment out to disable the options.
#

BOOTMAGIC_ENABLE 				= no  # Virtual DIP switch configuration
MIDI_ENABLE      				= no  # MIDI support (+2400 to 4200)
POINTING_DEVICE_ENABLE  = no
MOUSEKEY_ENABLE  				= yes # Mouse keys(+4700)
EXTRAKEY_ENABLE  				= yes # Audio control and System control (+450)
CONSOLE_ENABLE   				= no  # Console for debug
COMMAND_ENABLE   				= yes # Commands for debug and configuration
CUSTOM_MATRIX    				= yes # Custom matrix file for the 67Manuform
NKRO_ENABLE      				= yes # USB Nkey Rollover
UNICODE_ENABLE   				= yes # Unicode
SWAP_HANDS_ENABLE				= no # Allow swapping hands of keyboard
API_SYSEX_ENABLE        = no
OLED_DRIVER_ENABLE      = yes
WPM_ENABLE              = yes

DEBOUNCE_TYPE = eager_pr

# project specific files
SRC = matrix.c \
			util.c

#ifdef OLED_DRIVER_ENABLE
	SRC += oled.c
#endif
