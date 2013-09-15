all:

.PHONY: all clean debug


PROGRAM = blink

SRC += blink.c
SRC += startup_ARMCM3.S

#DEFINES += __NO_SYSTEM_INIT
#INCLUDES += ./

LINKER_SCRIPTS = stm32l152.ld sections.ld
LDFLAGS += $(addprefix -T,$(LINKER_SCRIPTS))
$(PROGRAM): $(LINKER_SCRIPTS)

#LDFLAGS += -Wl,--start-group -lgcc -lc -lc -lm -lnosys -Wl,--end-group
#LDFLAGS += --specs=nano.specs
#LDFLAGS += -static

#CFLAGS += -Os

#LDFLAGS += -Xlinker -Map=$(PROGRAM).map
CLEAN_LIST += $(PROGRAM).map

TARGET_ARCH = -mthumb -mcpu=cortex-m3

CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
OC = $(CROSS_COMPILE)objcopy
OD = $(CROSS_COMPILE)objdump
GDB = $(CROSS_COMPILE)gdb

all: $(PROGRAM)
all: $(PROGRAM).dis
all: $(PROGRAM).bin

CLEAN_LIST += $(PROGRAM).dis
CLEAN_LIST += $(PROGRAM).bin
CLEAN_LIST += openocd.log

GCC_FLAGS += -g

SRC_C = $(filter %.c, $(SRC))
SRC_S = $(filter %.S, $(SRC))
SRC_s = $(filter %.s, $(SRC))

OBJ  = $(patsubst %.c,%.o,$(SRC_C))
OBJ += $(patsubst %.S,%.o,$(SRC_S))
OBJ += $(patsubst %.s,%.o,$(SRC_s))

$(PROGRAM): $(OBJ)
$(OBJ): $(MAKEFILE_LIST)

DEFINE_FLAGS = $(addprefix -D,$(DEFINES))
INCLUDE_FLAGS =  $(addprefix -I,$(INCLUDES))

PREPROC_FLAGS += $(DEFINE_FLAGS) $(INCLUDE_FLAGS)
COMPILE_FLAGS += $(PREPROC_FLAGS)

CFLAGS += $(COMPILE_FLAGS)
ASFLAGS += $(COMPILE_FLAGS)

CFLAGS += $(GCC_FLAGS)
ASFLAGS += $(GCC_FLAGS)
LDFLAGS += $(GCC_FLAGS)

CLEAN_LIST += $(PROGRAM)
CLEAN_LIST += $(OBJ)

$(PROGRAM):
	$(LINK.o) $(OBJ) $(LOADLIBES) $(LDLIBS) -o $@

%.bin: %
	$(OC) -O binary $< $@

%.dis: %
	$(OD) -S $< >$@

attach: $(PROGRAM)
	$(GDB) $(PROGRAM) -x attach.gdb

run: $(PROGRAM)
	$(GDB) $(PROGRAM) -x run.gdb

ddd-attach: $(PROGRAM)
	ddd --debugger $(GDB) --command=attach.gdb $(PROGRAM)

ddd-run: $(PROGRAM)
	ddd --debugger $(GDB) --command=run.gdb $(PROGRAM)

flash: $(PROGRAM).bin
	openocd -f c232hm-edhsl-0.cfg -f stm32l.cfg -f flash_blink.cfg

clean:
	rm -rf $(CLEAN_LIST)


