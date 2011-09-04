CROSS_COMPILE=arm-none-eabi-
include ../common/common.mk

ASFLAGS = -mcpu=arm926ej-s -g
CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS = -T $*.ld -nostartfiles -nostdlib

APP = test 
DEBUG_APP = test

APP_TARGETS = $(APP) $(addsuffix .hd,$(APP)) $(addsuffix .dis, $(APP))

.PHONY: all
all: $(APP_TARGETS)

test: startup.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(addsuffix .elf, $(APP))
	rm -rf $(addsuffix .map, $(APP))
	rm -rf $(APP_TARGETS)

debug: $(DEBUG_APP)
	ddd --debugger $(GDB) --command $(DEBUG_APP).gdb $<


