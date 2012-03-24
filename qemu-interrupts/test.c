#include <stdint.h>

enum {
    RXFE = 0x10,
    TXFF = 0x20,
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

typedef volatile struct {
    uint32_t IRQSTATUS;
    uint32_t FIQSTATUS;
    uint32_t RAWINTR;
    uint32_t INTSELECT;
    uint32_t INTENABLE;
    uint32_t INTENCLEAR;
    uint32_t SOFTINT;
    uint32_t SOFTINTCLEAR;
    uint32_t PROTECTION;
    uint8_t reserved0[0xC];
    uint32_t VECTADDR;
    uint32_t DEFVECTADDR;
    uint8_t reserved1[0x100 - 0x38];
    uint32_t VECTADDRn[16];
    uint8_t reserved2[0x200 - 0x140];
    uint32_t VECTCNTLn[16];
} pl190_T;

pl190_T * const VIC = (pl190_T *)0x10140000;
pl011_T * const UART0 = (pl011_T *)0x101f1000;

void __attribute__((interrupt)) undef_handler() {
	for(;;);
}

void __attribute__((interrupt)) swi_handler() {
	for(;;);
}

void __attribute__((interrupt)) prefetch_abort_handler() {
	for(;;);
}

void __attribute__((interrupt)) data_abort_handler() {
	for(;;);
}

void __attribute__((interrupt)) irq_handler() {
    UART0->ICR = UART0->MIS;
}

void __attribute__((interrupt)) fiq_handler() {
	for(;;);
}

void copy_vectors(void)
{
    extern const uint32_t _vectors_start;
    extern const uint32_t _vectors_end;
    uint32_t *vectors_dst;
    const uint32_t *vectors_src = &_vectors_start;
    
    vectors_dst = (uint32_t *)0x00000000;
    while(vectors_src < &_vectors_end)
    {
        *vectors_dst++ = *vectors_src++;
    }
}

void print_uart0(const char *s) {
	while(*s != '\0') { /* Loop until end of string */
		UART0->DR = *s; /* Transmit char */
		s++; /* Next char */
	}
}

void enable_irq(void)
{
    asm volatile(
            "MRS r0, cpsr\n\t"
            "BIC r0, r0, #0x80\n\t"
            "MSR cpsr, r0\n\t"
            :::"r0");
}

void c_entry() {
    
    copy_vectors();

    VIC->INTENABLE = 1<<12;
    enable_irq();

    UART0->IMSC = 0xFFFF;
    UART0->IFLS = 0x0000;

	print_uart0("Hello world!\n");
}

