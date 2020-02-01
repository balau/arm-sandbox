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
.global Reset_Handler
.global Empty_Exception_Handler

Reset_Handler: 

 LDR r0, =0x101f1000
 LDR r1, =0x61
 STR r1, [r0]

 LDR sp, =stack_top
 LDR lr, =Reset_Handler_1
 LDR pc, =relocate_exceptions
Reset_Handler_1:
 
 LDR r0, =0x101f1000
 LDR r1, =0x62
 STR r1, [r0]
 
 LDR lr, =c_entry_return
 LDR pc, =c_entry
c_entry_return:
 SWI 0x01

Empty_Exception_Handler:
 LDR r0, =0x101f1000
 LDR r1, =0x65
 STR r1, [r0]
 B .
