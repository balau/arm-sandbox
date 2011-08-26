ENTRY(_Reset)
SECTIONS
{
  . = 0x00100000;
  .startup . : { startup.o }
  .text : { *(.text) }
  .rodata : { *(.rodata) }
  .data : { *(.data) }
  .bss : { *(.bss) }
  . = . + 0x1000; /* 4kB of stack memory */
  stack_top = .;
}

