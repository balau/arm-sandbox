CROSS_COMPILE=arm-linux-gnueabi-
include ../common/common.mk

ASFLAGS = -mcpu=arm926ej-s -g
CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS = -T $*.ld -nostdlib -Xlinker --build-id=none

APP = test
DEBUG_APP = test

APP_TARGETS = $(APP) $(APP).bin

.PHONY: all
all: $(APP_TARGETS)

test: vectors.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(APP_TARGETS)

debug: $(DEBUG_APP).bin
	xterm -e 'qemu-system-arm -m 128M -M versatilepb -s -nographic -S -kernel $(DEBUG_APP).bin'&
	ddd --debugger $(GDB) --command $(DEBUG_APP)-qemu.gdb

run: $(DEBUG_APP).bin
	qemu-system-arm -m 128M -M versatilepb -serial stdio -kernel $< -d cpu,in_asm -singlestep -D ./qemu.log


