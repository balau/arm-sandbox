
ASFLAGS = -mcpu=arm926ej-s -g
CFLAGS = -mcpu=arm926ej-s -g -mno-thumb-interwork -marm
#ASFLAGS = -g
#CFLAGS = -g -mcpu=arm926ej-s
LDFLAGS = -T $*.ld
APP = test 
#MKIMAGE = ../u-boot-2010.03/tools/mkimage
MKIMAGE = mkimage

.PHONY: all
all: run

.PHONY: clean
clean:
	rm -rf zero1kB.bin
	rm -rf test.elf test.bin flash.bin test.uimg
	rm -rf startup.o test.o

zero1kB.bin:
	dd if=/dev/zero of=$@ bs=1 count=1024

debug: zero1kB.bin
	#xterm -e 'sudo qemu-system-arm -m 128M -M versatilepb -s -nographic -S -kernel zero1kB.bin -net nic -net tap -tftp .'&
	xterm -e 'qemu-system-arm -m 128M -M versatilepb -s -nographic -S -kernel zero1kB.bin'&
	sleep 2
	ddd --debugger $(GDB) --command u-boot-qemu.gdb

run: flash.bin
	printf "bootm 0x%X\n" $$(expr $$(stat -c%s u-boot.bin) + 65536)
	qemu-system-arm -m 128M -M versatilepb -nographic -kernel flash.bin

debugtest: flash.bin
	printf "bootm 0x%X\n" $$(expr $$(stat -c%s u-boot.bin) + 65536)
	xterm -e 'qemu-system-arm -m 128M -M versatilepb -nographic -kernel flash.bin -s -S -singlestep -semihosting' &
	sleep 2
	ddd --debugger $(GDB) --command u-boot-qemu.gdb

flash.bin: u-boot.bin test.uimg
	cat $^ > $@

test.uimg: test.bin
	$(MKIMAGE) -A arm -C none -O linux -T kernel -d $< -a 0x00100000 -e 0x00100000 $@

test.elf: startup.o

u-boot.bin: u-boot-2010.03.bin
	cp $< $@

include ../common/arm.mk

