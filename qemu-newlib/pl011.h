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

enum {
    PL011_FR_RXFE = 0x10,
    PL011_FR_TXFF = 0x20,
};

typedef volatile struct {
    uint32_t DR;
    uint32_t RSR_ECR;
    uint8_t reserved1[0x10];
    const uint32_t FR;
    uint8_t reserved2[0x4];
    uint32_t LPR;
    uint32_t IBRD;
    uint32_t FBRD;
    uint32_t LCR_H;
    uint32_t CR;    
    uint32_t IFLS;
    uint32_t IMSC;
    const uint32_t RIS;
    const uint32_t MIS;
    uint32_t ICR;
    uint32_t DMACR;    
} pl011_T;

