
CC = arm-none-linux-gnueabi-gcc
CFLAGS += -static -pg

run: zImage rootfs
	qemu-system-arm -M versatilepb -m 128M -kernel zImage_gnu -initrd rootfs -append "root=/dev/ram rdinit=/test"

rootfs.gz : rootfs
	gzip $< -c >$@

rootfs: test
	echo test | cpio -o --format=newc > $@

