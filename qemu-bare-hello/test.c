/*
void __attribute__((interrupt)) Undef_Handler() {
	for(;;);
}

void __attribute__((interrupt)) SWI_Handler() {
	for(;;);
}

void __attribute__((interrupt)) Abort_Handler() {
	for(;;);
}

void __attribute__((interrupt)) IRQ_Handler() {
	for(;;);
}

void __attribute__((interrupt)) FIQ_Handler() {
	for(;;);
}
*/


volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;

void print_uart0(const char *s) {
	while(*s != '\0') { /* Loop until end of string */
		*UART0DR = *s; /* Transmit char */
		s++; /* Next char */
	}
}

void c_entry() {
	print_uart0("Hello world!\n");
}

