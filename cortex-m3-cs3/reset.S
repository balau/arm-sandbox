.text
.thumb

.global __cs3_reset

.thumb_func
__cs3_reset:
    # add peripherals and memory initialization here
    LDR r0, =__cs3_start_asm
    BX r0


.thumb_func
__cs3_start_asm:
    # add assembly initializations here
    LDR r0, =__cs3_start_c
    BX r0

.end

