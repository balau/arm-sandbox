ENTRY(_vectors_start)
SECTIONS
{
  . = 0x10000; 
  .text : {
	  vectors.o
	  *(.text .rodata)	  
	}
  .data : { *(.data) }
  .bss : { *(.bss) }
  . = . + 0x1000; /* 4kB of stack memory */
  stack_top = .;
  . = . + 0x1000; /* 4kB of irq stack memory */
  irq_stack_top = .;
}

