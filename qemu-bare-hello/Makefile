
ASFLAGS = -mcpu=arm926ej-s -g
CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS = -T $*.ld

APP = test 
DEBUG_APP = test

APP_TARGETS = $(addsuffix .elf, $(APP))

.PHONY: all
all: $(APP_TARGETS)

test.elf: startup.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(APP_TARGETS)

debug: $(DEBUG_APP).elf
	xterm -e 'qemu-system-arm -m 128M -M versatilepb -m 128M -s -nographic -S -kernel test.bin'&
	ddd --debugger $(GDB) --command $(DEBUG_APP)-qemu.gdb

qemu: $(DEBUG_APP).bin
	xterm -e 'qemu-system-arm -m 128M -M versatilepb -m 128M -nographic -kernel $<'

include ../common/arm.mk

