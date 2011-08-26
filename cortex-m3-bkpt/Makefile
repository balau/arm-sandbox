CROSS_COMPILE=arm-none-eabi-
#CROSS_COMPILE=arm-linux-gnueabi-
CC = $(CROSS_COMPILE)gcc
OC = $(CROSS_COMPILE)objcopy
OD = $(CROSS_COMPILE)objdump
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

CFLAGS += -mthumb -march=armv7 -g
ASFLAGS += -mthumb -march=armv7 -g
LDFLAGS += -T ./lm3s6965.ld -nostdlib -nostartfiles

all: test_bkpt test_bkpt.dis test_bkpt.bin test_bkpt.sym

debug: test_bkpt.bin gdb.init
	qemu-system-arm -M lm3s6965evb -s -S --kernel test_bkpt.bin &
	ddd --debugger $(CROSS_COMPILE)gdb --command=gdb.init

clean:
	rm -f test_bkpt.bin
	rm -f test_bkpt.dis
	rm -f test_bkpt
	rm -f gdb.init

gdb.init:
	echo "file test_bkpt" > $@
	echo "target remote localhost:1234" >> $@

test_bkpt.bin: test_bkpt
test_bkpt.dis: test_bkpt
test_bkpt.sym: test_bkpt

%.bin: %
	$(OC) -O binary $< $@

%.dis: %
	$(OD) -dS $< >$@

%.sym: %
	$(OD) -t $< >$@

