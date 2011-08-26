CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
OC = $(CROSS_COMPILE)objcopy
OD = $(CROSS_COMPILE)objdump

CFLAGS = -O0 -g -Wall
LDFLAGS = -Xlinker -Map=$@.map -T test.ld -Wall -nostartfiles

QEMU = /home/francesco/src/arm/meego/qemu/arm-softmmu/qemu-system-arm

all: test

clean:
	rm -rf test.bin test test.o test.map startup.o qemu_startup.o

test: test.o startup.o vect.o exceptions.o

#startup.o 
#syscalls.o

run: test.bin
	$(QEMU) -M versatilepb -kernel $< -serial stdio

runhosted: test.bin
	$(QEMU) -M versatilepb -kernel $< -serial stdio -semihosting

debug: test.bin
	xterm -e '$(QEMU) -M versatilepb -kernel $< -serial stdio -S -s'&
	ddd --debugger $(CROSS_COMPILE)gdb -- -x test.gdb test
	
%.bin: %
	$(OC) -O binary $< $@

%.hex: %.bin
	hexdump -v -e '"%08_ax: %08X\n"' $< > $@
	
%.code: %
	$(OD) -D -S $< > $@
