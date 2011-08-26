.section INTERRUPT_VECTOR, "x"
.global _Reset
_Reset:
	LDR pc, Reset_Handler_Addr 
	LDR pc, Undef_Handler_Addr
	LDR pc, SWI_Handler_Addr
	LDR pc, Abort_Handler_Addr
	LDR pc, Abort_Handler_Addr
$reserved: B $reserved
	LDR pc, IRQ_Handler_Addr
	LDR pc, FIQ_Handler_Addr


Reset_Handler_Addr: .long Reset_Handler
Undef_Handler_Addr: .long Undef_Handler
SWI_Handler_Addr:   .long SWI_Handler
Abort_Handler_Addr: .long Abort_Handler
IRQ_Handler_Addr:   .long IRQ_Handler
FIQ_Handler_Addr:   .long FIQ_Handler

Reset_Handler:
	LDR sp, =stack_top
	BL c_entry
	B .

