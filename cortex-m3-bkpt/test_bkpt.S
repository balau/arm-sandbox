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
    LDR r0, [sp, #24]
    ADD r0, #2
    STR r0, [sp, #24]
    BX lr

.end

