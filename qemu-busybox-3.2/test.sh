wget http://www.kernel.org/pub/linux/kernel/v3.0/linux-3.2.tar.bz2
tar xjf linux-3.2.tar.bz2
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-
cd linux-3.2
make vexpress_defconfig
make all
cd ..

wget http://busybox.net/downloads/busybox-1.19.3.tar.bz2
tar xjf busybox-1.19.3.tar.bz2
cd busybox-1.19.3
make defconfig
sed -e 's/.*STATIC.*/CONFIG_STATIC=y/' -i .config
make install

cd _install
mkdir -p proc sys dev etc etc/init.d
echo '#!/bin/sh' > etc/init.d/rcS
echo 'mount -t proc none /proc' >> etc/init.d/rcS
echo 'mount -t sysfs none /sys' >> etc/init.d/rcS
echo '/sbin/mdev -s' >> etc/init.d/rcS
chmod +x etc/init.d/rcS
ln -s sbin/init init
find . | cpio -o --format=newc > ../../rootfs
cd ../..
gzip -c rootfs > rootfs.gz

qemu-system-arm -M vexpress-a9 -kernel linux-3.2/arch/arm/boot/zImage -initrd rootfs.gz -serial stdio -append "console=tty1"

