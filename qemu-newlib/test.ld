/*ENTRY(_Reset)*/
SECTIONS
{
  . = 0x10000;
  .ro : {
    startup.o (.text)
    *(.text)
    *(.rodata)
  }
  /*
  .startup : { startup.o (.text) }
  .text : { *(.text) }  
  .data : { *(.data) }
  .bss : { *(.bss) }
  .rodata : { *(.rodata) }
  */
  .rw : {      
      *(.data)
      *(.bss)
      *(COMMON)
  }
  heap_low = .; /* for _sbrk */  
  . = . + 0x10000; /* 64kB of heap memory */
  heap_top = .; /* for _sbrk */  
  . = . + 0x10000; /* 64kB of stack memory */
  stack_top = .; /* for startup.s */
 /*.note.gnu.build-id : { }
 .other : { *(*) }
 /* /DISCARD/ : { *(*) } */
}

