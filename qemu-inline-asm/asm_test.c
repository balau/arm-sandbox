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

