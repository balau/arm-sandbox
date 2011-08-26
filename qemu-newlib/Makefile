CROSS_COMPILE = arm-none-eabi-
#CROSS_COMPILE = arm-linux-gnueabi-

CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld
OC = $(CROSS_COMPILE)objcopy
OD = $(CROSS_COMPILE)objdump


#ASFLAGS = -mcpu=arm926ej-s
#CFLAGS = -mcpu=arm926ej-s
ASFLAGS += -mcpu=cortex-a8
CFLAGS += -mcpu=cortex-a8
CFLAGS += -Wall -save-temps -O0
CFLAGS += -I ./newlib-1.18.0/newlib/libc/include
LDFLAGS += -Xlinker "-Map=$*.map"
LDFLAGS += -nostdlib 
LDFLAGS += -T test.ld
#LDFLAGS += -lgcc
#LDFLAGS += -Xlinker "--build-id=none"
#LDFLAGS += -T generic.ld


#LDLIBS += ./newlib-1.18.0/arm-linux-gnueabi/newlib/libc.a
LDLIBS += ./newlib-1.18.0/arm-none-eabi/newlib/libc.a
LDLIBS += /home/francesco/CodeSourcery/Sourcery_G++_Lite/lib/gcc/arm-none-eabi/4.5.1/libgcc.a
#LDLIBS += ./newlib-1.18.0/arm-none-eabi/libgloss/arm/crt0.o
#LDLIBS += /home/francesco/CodeSourcery/Sourcery_G++_Lite/lib/gcc/arm-none-eabi/4.4.1/armv6-m/libgcc.a
#LDLIBS += /home/francesco/CodeSourcery/Sourcery_G++_Lite/arm-none-eabi/lib/libc.a


.PHONY: all
all: test test.code test.hex test.bin

test: startup.o test.o syscalls.o

.PHONY: clean
clean:
	rm -f test.o startup.o syscalls.o
	rm -f test.i startup.i syscalls.i
	rm -f test.s syscalls.s
	rm -f test test.bin
	rm -f test.hex
	rm -f test.map
	rm -f test.code

run: test.bin
	qemu-system-arm -M realview-pb-a8 -serial stdio -kernel $<

%.bin: %
	$(OC) -O binary $< $@

%.hex: %.bin
	hexdump -C $< >$@

%.code : %
	$(OD) -dS $< >$@

