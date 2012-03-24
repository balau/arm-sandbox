wget http://www.kernel.org/pub/linux/kernel/v3.0/linux-3.2.tar.bz2
tar xjf linux-3.2.tar.bz2
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-
cd linux-3.2
make vexpress_defconfig
make all
cd ..
arm-linux-gnueabi-gcc -static init.c -o init
echo init|cpio -o --format=newc > rootfs
qemu-system-arm -M vexpress-a9 -kernel linux-3.2/arch/arm/boot/zImage -initrd rootfs -serial stdio -append "console=tty1"

qemu-system-arm -M vexpress-a9 -kernel linux-3.2/arch/arm/boot/zImage -initrd rootfs -serial stdio -append "console=tty1" -s -S

ddd --debugger ${CROSS_COMPILE}gdb
(gdb) cd linux-3.2
(gdb) file vmlinux
(gdb) target remote localhost:1234

