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
