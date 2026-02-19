# GPIO_.inc

# ------------------------------------------------------------
# GPIO REGISTER OFFSETS
# ------------------------------------------------------------

.equ GPIO_INPUT_VAL,     0x000   # Read input value
.equ GPIO_INPUT_EN,      0x004   # Enable input
.equ GPIO_OUTPUT_EN,     0x008   # Enable output
.equ GPIO_OUTPUT_VAL,    0x00C   # Output value
.equ GPIO_INPUT_PULLUP,  0x010   # Enable pull-up
.equ GPIO_OUTPUT_XOR,    0x040   # Invert output logic

.equ IOF_E,              0x038   # IOF enable/disable register

# ------------------------------------------------------------
# PIN BITMASKS (MATCH C DEFINES)
# ------------------------------------------------------------

.equ PIN_2,   0x40000000
.equ PIN_3,   0x00080000
.equ PIN_4,   0x00100000
.equ PIN_5,   0x00200000
.equ PIN_6,   0x00400000
.equ PIN_8,   0x00000001
.equ PIN_9,   0x00000002
.equ PIN_18,  0x00001000
.equ PIN_19,  0x00002000

# ------------------------------------------------------------
# SIGNAL NAMES
# ------------------------------------------------------------

.equ TST, PIN_8
.equ ACK, PIN_9 
.equ FLA, PIN_18
.equ OLA, PIN_19   # OVERFLOW LEVEL ALARM

.equ GREEN_LED,  PIN_3
.equ YELLOW_LED, PIN_5
.equ RED_LED,    PIN_6

.equ GPIO_RGB_PINS, GREEN_LED | YELLOW_LED | RED_LED

# ------------------------------------------------------------
# GROUP MASKS USED IN setupGPIO.S
# ------------------------------------------------------------

.equ INPUT,  PIN_8 | PIN_9 | PIN_18 | PIN_19
.equ OUTPUT, PIN_3 | PIN_5 | PIN_6
