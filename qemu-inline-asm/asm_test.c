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
#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_ror_imm(uint32_t v, uint32_t sh) {
    uint32_t d;    
    asm ("ROR %[Rd], %[Rm], %[Is]" : [Rd] "=r" (d) : [Rm] "r" (v), [Is] "i" (sh));
    return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ror(uint32_t v, uint32_t sh) {
    uint32_t d;
    asm ("ROR %[Rd], %[Rm], %[Rs]" : [Rd] "=r" (d) : [Rm] "r" (v), [Rs] "r" (sh));
    return d;
}

int main() {
    uint32_t val;
    
    val = 0x22;
    printf("val = 0x%08X\n", val);
    printf("arm_ror(val, 1) = 0x%08X\n", arm_ror(val, 1));
    printf("arm_ror(val, 2) = 0x%08X\n", arm_ror(val, 2));
    printf("arm_ror_imm(val, 3) = 0x%08X\n", arm_ror_imm(val, 3));
    printf("arm_ror_imm(val, 4) = 0x%08X\n", arm_ror_imm(val, 4));
    return 0;
}

