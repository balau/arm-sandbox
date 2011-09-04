CROSS_COMPILE=arm-none-eabi-
#CROSS_COMPILE=arm-linux-gnueabi-

include ../common/common.mk

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
	rm -f test_bkpt.sym
	rm -f test_bkpt
	rm -f gdb.init

gdb.init:
	echo "file test_bkpt" > $@
	echo "target remote localhost:1234" >> $@

test_bkpt: test_bkpt.S

