.section .text
.align 2
.globl checkBot
#include "GPIO_.inc"
#include "memoryMap.inc"

.equ ON,  0x1
.equ OFF, 0x0

# int checkBot(uint32_t pinMask)
# a0 = pinMask (TST/FLA/OLA/ACK)
# returns:
#   a0 = ON  (1) if pin is HIGH
#   a0 = OFF (0) if pin is LOW

checkBot:
    addi sp, sp, -16          # allocate stack frame
    sw   ra, 12(sp)           # save return address

    li   t0, GPIO_CTRL_ADDR   # GPIO base address
    lw   t1, GPIO_INPUT_VAL(t0)  # read input register

    and  t1, t1, a0           # mask with requested pin(s)
    beqz t1, pinOFF           # if result == 0 → pin is LOW

    li   a0, ON               # pin HIGH → return ON
    j    exit

pinOFF:
    li   a0, OFF              # pin LOW → return OFF

exit:
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret
