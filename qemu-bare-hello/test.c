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

