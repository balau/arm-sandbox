CROSS_COMPILE=arm-none-eabi-

include ../common/common.mk

CFLAGS += -mthumb -march=armv7 -mfix-cortex-m3-ldrd -g
ASFLAGS += -mthumb -march=armv7 -mfix-cortex-m3-ldrd -g
LDFLAGS += -T lm3s6965.ld

#CFLAGS += --verbose
#LDFLAGS += -Xlinker --verbose
LDFLAGS += -Xlinker -Map=main.map
#CFLAGS += -Xassembler --verbose

TARGETS = main main.dis main.bin main.sym main.srec main.hd

all: $(TARGETS)

debug: all
	qemu-system-arm -M lm3s6965evb -s -S --kernel main.bin &
	ddd --debugger $(CROSS_COMPILE)gdb --command=main.gdb

trace: all
	qemu-system-arm -M lm3s6965evb --kernel main.bin --serial stdio -d cpu,in_asm,op,exec -singlestep
	mv /tmp/qemu.log .	

run: all
	qemu-system-arm -M lm3s6965evb --kernel main.bin --serial stdio

clean:
	rm -f $(TARGETS)
	rm -f main.map
	rm -f qemu.log

main: reset.S syscalls.c

