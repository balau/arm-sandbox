#include <stdint.h>

#define UART0_BASE_ADDR 0x101f1000
#define UART0_DR (*((volatile uint32_t *)(UART0_BASE_ADDR + 0x000)))
#define UART0_IMSC (*((volatile uint32_t *)(UART0_BASE_ADDR + 0x038)))

#define VIC_BASE_ADDR 0x10140000
#define VIC_INTENABLE (*((volatile uint32_t *)(VIC_BASE_ADDR + 0x010)))

void __attribute__((interrupt)) irq_handler() {
    /* echo the received character + 1 */
    UART0_DR = UART0_DR + 1;
}

/* all other handlers are infinite loops */
void __attribute__((interrupt)) undef_handler(void) { for(;;); }
void __attribute__((interrupt)) swi_handler(void) {	for(;;); }
void __attribute__((interrupt)) prefetch_abort_handler(void) { for(;;); }
void __attribute__((interrupt)) data_abort_handler(void) { for(;;); }
void __attribute__((interrupt)) fiq_handler(void) {	for(;;); }

void copy_vectors(void) {
    extern uint32_t vectors_start;
    extern uint32_t vectors_end;
    uint32_t *vectors_src = &vectors_start;
    uint32_t *vectors_dst = (uint32_t *)0;

    while(vectors_src < &vectors_end)
        *vectors_dst++ = *vectors_src++;
}

void main(void) {
    /* enable UART0 IRQ */
    VIC_INTENABLE = 1<<12;
    /* enable RXIM interrupt */
    UART0_IMSC = 1<<4;
    for(;;);
}

