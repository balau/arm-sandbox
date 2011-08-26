ENTRY(Reset_Handler)

SECTIONS
{
 . = 0x10000;
 .startup : { startup.o }

 __load_start_vect = .;
 __copy_start_vect = 0;
 .vect : { vect.o }
 __load_stop_vect = .;
 
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss) }
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
}
