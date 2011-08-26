KERNEL = zImage
ROOTFS = rootfs.img
ROOTFSGZ = $(ROOTFS).gz
FLASH = flash.bin
UBOOT = u-boot.bin
KERNELIMG = $(KERNEL).uimg
ROOTIMG = rootfs.uimg

.PHONY: run
run: $(FLASH)
	qemu-system-arm -M versatilepb -m 128 -kernel $(FLASH) -serial stdio

$(FLASH): $(KERNELIMG) $(ROOTIMG) $(UBOOT)
	test -f $@ || dd if=/dev/zero of=$@ bs=1 count=6M
	dd if=$(UBOOT) of=$@ conv=notrunc bs=1
	dd if=$(KERNELIMG) of=$@ conv=notrunc bs=1 seek=2M
	dd if=$(ROOTIMG) of=$@ conv=notrunc bs=1 seek=4M

$(KERNELIMG): $(KERNEL)
	mkimage -A arm -C none -O linux -T kernel -d $< -a 0x00010000 -e 0x00010000 $@

$(ROOTIMG): $(ROOTFSGZ)
	mkimage -A arm -C none -O linux -T ramdisk -d $< -a 0x00800000 -e 0x00800000 $@



