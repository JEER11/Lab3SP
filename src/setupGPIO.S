    .section .text
    .align 2
    .globl setupGPIO

#include "memoryMap.inc"
#include "GPIO_.inc"

# void setupGPIO(void)
setupGPIO:
    addi sp, sp, -16          # allocate stack frame
    sw   ra, 12(sp)           # save return address

    # t0 = base address of GPIO controller
    li   t0, GPIO_CTRL_ADDR

    # Disable IOF on the pins we’re using (set to GPIO function)
    sw   x0, IOF_E(t0)

    # -----------------------------
    # Configure INPUT pins
    # -----------------------------
    li   t1, INPUT                 # TST | ACK | FLA | OLA
    sw   t1, GPIO_INPUT_EN(t0)     # enable input
    sw   t1, GPIO_INPUT_PULLUP(t0) # enable pull-up resistors

    # -----------------------------
    # Configure OUTPUT pins (LEDs)
    # -----------------------------
    li   t1, OUTPUT                # GREEN | YELLOW | RED
    sw   t1, GPIO_OUTPUT_EN(t0)    # enable outputs

    # Clear all outputs initially
    sw   x0, GPIO_OUTPUT_VAL(t0)

    # Restore RA and stack, return
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret
