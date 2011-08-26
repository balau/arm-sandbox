
ASFLAGS = -mcpu=arm926ej-s -g
CFLAGS = -mcpu=arm926ej-s -g
LDFLAGS = -T $*.ld

APP = test 
DEBUG_APP = test

APP_TARGETS = $(addsuffix .hd,$(APP)) $(addsuffix .code, $(APP)) $(addsuffix .elf, $(APP))

.PHONY: all
all: $(APP_TARGETS)

test.elf: startup.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(addsuffix .elf, $(APP))
	rm -rf $(addsuffix .map, $(APP))
	rm -rf $(APP_TARGETS)

debug: $(DEBUG_APP).elf
	ddd --debugger $(GDB) --command $(DEBUG_APP).gdb $<

include ../common/arm.mk

