CODESOURCERY_PATH = /home/francesco/CodeSourcery/Sourcery_G++_Lite/
SCRIPTS_PATH = $(CODESOURCERY_PATH)/arm-none-eabi/lib/
GCCLIBS_PATH = $(CODESOURCERY_PATH)/lib/gcc/arm-none-eabi/4.4.1/

#COLLECTED_LDFLAGS = --sysroot=$(CODESOURCERY_PATH)bin/../arm-none-eabi -X $(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1/crti.o $(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1/crtbegin.o -L$(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1 -L$(CODESOURCERY_PATH)bin/../lib/gcc -L$(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1/../../../../arm-none-eabi/lib -L$(CODESOURCERY_PATH)bin/../arm-none-eabi/lib --start-group -lgcc -lc --end-group $(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1/crtend.o $(CODESOURCERY_PATH)bin/../lib/gcc/arm-none-eabi/4.4.1/crtn.o

#ASFLAGS = -mcpu=arm926ej-s -g
#CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS = $(COLLECTED_LDFLAGS) -T qemu-hosted.ld

APP = main
DEBUG_APP = main

APP_TARGETS = $(addsuffix .hd,$(APP)) $(addsuffix .code, $(APP)) $(addsuffix .elf, $(APP)) $(addsuffix .bin, $(APP))

.PHONY: all clean debug run qemu

all: $(APP_TARGETS)

clean:
	rm -rf *.o
	rm -rf $(addsuffix .elf, $(APP))
	rm -rf $(addsuffix .map, $(APP))
	rm -rf $(APP_TARGETS)
	rm -rf zero1kB.bin

debug: $(DEBUG_APP).elf
	ddd --debugger $(GDB) --command $(DEBUG_APP).gdb $<

run: $(DEBUG_APP).bin
	qemu-system-arm -nographic -monitor null -serial null -semihosting -kernel $<

zero1kB.bin:
	dd if=/dev/zero of=$@ bs=1 count=1024

qemu: $(DEBUG_APP).elf zero1kB.bin
	xterm -e 'qemu-system-arm -semihosting -s -M versatilepb -s -nographic -S -kernel zero1kB.bin'&
	ddd --debugger $(GDB) --command $(DEBUG_APP)-qemu.gdb

include ../common/arm.mk

%.elf: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

