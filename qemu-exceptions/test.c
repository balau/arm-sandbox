#include <stdint.h>
#include "exceptions.h"

volatile uint32_t * const UART0DR = (uint32_t *)0x101f1000;

typedef void (*exc_handler_t)(void);

void print_uart0(const char *s) {
 while(*s != '\0') { /* Loop until end of string */
 *UART0DR = (uint32_t)(*s); /* Transmit char */
 s++; /* Next char */
 }
}

void __attribute__ ((interrupt("SWI"))) swi_handler() {
  *UART0DR = (uint32_t)('S');
  *UART0DR = (uint32_t)('W');
  *UART0DR = (uint32_t)('I');
  *UART0DR = (uint32_t)('\n');
}

const char s_hex_chars[17] = "0123456789ABCDEF";

void print32(uint32_t value) {
	static char s_print32[10];
	int ii;
	for(ii = 0; ii < 8; ii++) {		
		s_print32[7-ii] = s_hex_chars[value & 0xF];
		value >>= 4;
	}
	s_print32[8] = '\n';
	s_print32[9] = '\0';
	print_uart0(s_print32);
}

void c_entry() {
 *UART0DR = (uint32_t)('c');
 print_uart0("Hello world!\n");
 {
	int ii;
	uint32_t *pMem = 0;
	for(ii = 0; ii < 20; ii++)
		print32(*pMem++);
 }
 set_exception(EXC_SWI, swi_handler);
 {
	int ii;
	uint32_t *pMem = 0;
	for(ii = 0; ii < 20; ii++)
		print32(*pMem++);
 }
 //for(;;);
}
