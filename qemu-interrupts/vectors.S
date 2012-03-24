    .text
    .code 32

    .global _vectors_start
    .global _vectors_end

    .align 4
_vectors_start:
    LDR PC, reset_handler_addr
    LDR PC, undef_handler_addr
    LDR PC, swi_handler_addr
    LDR PC, prefetch_abort_handler_addr
    LDR PC, data_abort_handler_addr
    B .
    LDR PC, irq_handler_addr
    LDR PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word undef_handler
swi_handler_addr: .word swi_handler
prefetch_abort_handler_addr: .word prefetch_abort_handler
data_abort_handler_addr: .word data_abort_handler
irq_handler_addr: .word irq_handler
fiq_handler_addr: .word fiq_handler

    .align 4
_vectors_end:


reset_handler:

    MRS r0, cpsr

    BIC r1, r0, #0x1F
    ORR r1, r1, #0x12
    MSR cpsr, r1
    LDR sp, =irq_stack_top

    MSR cpsr, r0
    LDR sp, =stack_top

	BL c_entry
	B .

    .end
    


