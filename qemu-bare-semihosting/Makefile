CROSS_COMPILE = arm-none-eabi-
include ../common/common.mk

#ASFLAGS = -mcpu=arm926ej-s -g
#CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS += -T qemu-hosted.ld

APP = main
DEBUG_APP = main

APP_TARGETS = $(addsuffix .hd,$(APP)) $(addsuffix .dis, $(APP)) $(addsuffix .bin, $(APP)) $(APP)

.PHONY: all clean debug run qemu

all: $(APP_TARGETS)

clean:
	rm -rf *.o
	rm -rf $(addsuffix .map, $(APP))
	rm -rf $(APP_TARGETS)
	rm -rf zero1kB.bin

debug: $(DEBUG_APP)
	ddd --debugger $(GDB) --command $(DEBUG_APP).gdb $<

run: $(DEBUG_APP).bin
	qemu-system-arm -nographic -monitor null -serial null -semihosting -kernel $<

zero1kB.bin:
	dd if=/dev/zero of=$@ bs=1 count=1024

qemu: $(DEBUG_APP) zero1kB.bin
	xterm -e 'qemu-system-arm -semihosting -s -M versatilepb -s -nographic -S -kernel zero1kB.bin'&
	ddd --debugger $(GDB) --command $(DEBUG_APP)-qemu.gdb

main: main.c

