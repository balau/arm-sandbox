/*
 * Copyright 2020 Francesco Balducci
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
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
