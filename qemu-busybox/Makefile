#KERNEL = ../linux-2.6.33/arch/arm/boot/zImage
KERNEL = zImage
ROOTFS = rootfs.img.gz
ROOTFS-ext2 = rootfs.img.ext2
ROOTFS_DIR = ../busybox-1.16.0/_install/
LIB_DIR = /home/francesco/CodeSourcery/Sourcery_G++_Lite/arm-none-linux-gnueabi/libc/lib

.PHONY: run
run: $(KERNEL) $(ROOTFS)
	qemu-system-arm -M versatilepb -m 128 -kernel $(KERNEL) -initrd $(ROOTFS) -serial stdio -append "rdinit=/sbin/init rw"

test.elf: test.c
	arm-none-linux-gnueabi-gcc $< -o $@

.PHONY: $(ROOTFS)
$(ROOTFS): inittab rcS $(ROOTFS_DIR) $(ROOTFS_DIR)/bin/busybox test.elf
	cd $(ROOTFS_DIR);\
	mkdir -p lib dev proc sys etc etc/init.d;\
	cp ../../qemu-linux/inittab etc;\
	cp ../../qemu-linux/rcS etc/init.d;\
	cd lib;\
	cp $(LIB_DIR)/libc-2.10.1.so .;\
	ln -s libc-2.10.1.so libc.so;\
	ln -s libc.so libc.so.6;\
	cp $(LIB_DIR)/libm-2.10.1.so .;\
	ln -s libm-2.10.1.so libm.so;\
	ln -s libm.so libm.so.6;\
	cp $(LIB_DIR)/ld-2.10.1.so .;\
	ln -s ld-2.10.1.so ld-linux.so.3;\
	cp $(LIB_DIR)/libgcc_s.so.1 .;\
	ln -s libgcc_s.so.1 libgcc_s.so;\
	cd ..;\
	cp ../../qemu-linux/test.elf .;\
	find . | cpio -o --format=newc | gzip > ../../qemu-linux/$@

.PHONY: $(ROOTFS-ext2)
$(ROOTFS-ext2):
	rm -f $@
	dd if=/dev/zero of=$@ bs=1k count=4096
	echo y | mkfs.ext2 -i 1024 $@
	mkdir -p mnt_rootfs
	sudo mount -o loop $@ mnt_rootfs
	sudo rsync -a $(ROOTFS_DIR) mnt_rootfs
	sudo chown -R root:root mnt_rootfs
	sudo mknod mnt_rootfs/dev/console -m 660 c 5 1
	sudo mknod mnt_rootfs/dev/null -m 660 c 1 3
	sudo mknod mnt_rootfs/dev/ttyAMA0 -m 660 c 204 64
	sudo sync
	sudo umount mnt_rootfs
	rmdir mnt_rootfs	

