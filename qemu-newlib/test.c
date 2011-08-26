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

