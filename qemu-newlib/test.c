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
#include <stdlib.h>

extern char *heap_end; /* Defined in syscalls.c */

void c_entry() {
    char c;
    char *ptr = NULL;
    size_t alloc_size = 1;
    do {        
        c =getchar();
        printf("%d: %c\n", c, c);

        ptr = realloc(ptr, alloc_size);
        if(ptr == NULL) {
            puts("Out of memory!\nProgram halting.");
            for(;;);
        } else {
            printf("new alloc of %d bytes at address 0x%X\n", alloc_size, (unsigned int)ptr);
            alloc_size <<= 1;
            printf("Heap end = 0x%X\n", (unsigned int)heap_end);
        }
    } while (1);
}

