.section INTERRUPT_VECTOR, "xw"
.global _Reset
.global vect_addr

_Reset:
 LDR PC, reset_addr
 LDR PC, undef_addr
 LDR PC, swi_addr
 LDR PC, pabort_addr
 LDR PC, dabort_addr
 B .
 LDR PC, irq_addr
 LDR PC, fiq_addr

vect_addr:
reset_addr:  .word Reset_Handler
undef_addr:  .word Empty_Exception_Handler
swi_addr:    .word Empty_Exception_Handler
pabort_addr: .word Empty_Exception_Handler
dabort_addr: .word Empty_Exception_Handler
             .word 0
irq_addr:    .word Empty_Exception_Handler
fiq_addr:    .word Empty_Exception_Handler
