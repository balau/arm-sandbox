
AS = $(CROSS_COMPILE)as
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
GDB = $(CROSS_COMPILE)gdb

%.bin: %
	$(OBJCOPY) -O binary $< $@

%.hex: %
	$(OBJCOPY) -O ihex $< $@

%.srec: %
	$(OBJCOPY) -O srec $< $@

%.hd: %.bin
	hexdump $< > $@

%.dis: %
	$(OBJDUMP) -dS $< > $@

%.sym: %
	$(OBJDUMP) -t $< >$@

