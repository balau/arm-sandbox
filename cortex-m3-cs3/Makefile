CROSS_COMPILE=arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
OC = $(CROSS_COMPILE)objcopy
OD = $(CROSS_COMPILE)objdump
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

CFLAGS += -mthumb -march=armv7 -mfix-cortex-m3-ldrd -g
ASFLAGS += -mthumb -march=armv7 -mfix-cortex-m3-ldrd -g
LDFLAGS += -T lm3s6965.ld

all: main main.dis main.bin main.sym

debug: main.bin gdb.init
	qemu-system-arm -M lm3s6965evb -s -S --kernel main.bin &
	ddd --debugger $(CROSS_COMPILE)gdb --command=gdb.init

clean:
	rm -f main.bin
	rm -f main.dis
	rm -f main.sym
	rm -f main
	rm -f gdb.init

gdb.init:
	echo "file main" > $@
	echo "target remote localhost:1234" >> $@
	echo "break main" >> $@

main.bin: main
main.dis: main
main.sym: main

%.bin: %
	$(OC) -O binary $< $@

%.dis: %
	$(OD) -dS $< >$@

%.sym: %
	$(OD) -t $< >$@

