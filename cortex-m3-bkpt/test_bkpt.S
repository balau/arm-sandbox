
.text
.thumb

exc_vector:
    .word stack_top   /* 0: stack init */
    .word reset       /* 1: PC init */
    .word isr_default /* 2: NMI */
    .word isr_default /* 3: HW fault */
    .word isr_default /* 4: MPU */
    .word isr_default /* 5: bus */
    .word isr_default /* 6: usage */
    .word isr_default /* 7: reserved */
    .word isr_default /* 8: reserved */
    .word isr_default /* 9: reserved */
    .word isr_default /* 10: reserved */
    .word isr_default /* 11: svc */
    .word isr_debug   /* 12: debug */
    .word isr_default /* 13: reserved */
    .word isr_default /* 14: pendsv */
    .word isr_default /* 15: system tick */

.global reset

.thumb_func
reset:
    NOP
    BKPT 0xab
    B .

.thumb_func
isr_default:
    B .

.thumb_func
isr_debug:
    BX lr

.end

