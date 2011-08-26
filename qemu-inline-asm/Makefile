CROSS_COMPILE = arm-linux-gnueabi-
CC = $(CROSS_COMPILE)gcc

CPU = cortex-a8
QEMU_CPU = cortex-a8

ASFLAGS = -mcpu=$(CPU)
CFLAGS = -mcpu=$(CPU) -O2 -marm
LDFLAGS = -mcpu=$(CPU) -marm -static

.PHONY: all clean

all: asm_test asm_test.dis

run: asm_test
	qemu-arm -cpu $(QEMU_CPU) asm_test

#asm_test: asm_test.o

%.dis: %
	$(CROSS_COMPILE)objdump -d $< > $@

clean:
	rm -rf asm_test
	rm -rf asm_test.o
	rm -rf asm_test.dis

