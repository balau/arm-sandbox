
PFX = arm-none-eabi

AS = $(PFX)-as
CC = $(PFX)-gcc
LD = $(PFX)-ld
OC = $(PFX)-objcopy
OD = $(PFX)-objdump
GDB = $(PFX)-gdb

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.elf: %.o
	$(LD) $(LDFLAGS) -Map=$*.map $^ -o $@

%.bin: %.elf
	$(OC) -O binary $< $@

%.v: %.elf
	$(OC) -O verilog $< $@

%.hex: %.elf
	$(OC) -O ihex $< $@

%.hd: %.bin
	hexdump $< > $@

%.code: %.elf
	$(OD) -dS $< > $@

