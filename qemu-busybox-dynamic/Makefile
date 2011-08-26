KERNEL = zImage
ROOTFS_DIR = /srv/nfs/francesco/rootfs
BUSYBOX_DIR = ./busybox_dynamic
LIBC_DIR = /home/francesco/CodeSourcery/Sourcery_G++_Lite/arm-none-linux-gnueabi/libc

.PHONY: run rootfs

run: $(KERNEL) rootfs
	qemu-system-arm -M versatilepb -kernel $(KERNEL) -append "root=/dev/nfs nfsroot=10.0.2.2:/srv/nfs/francesco/rootfs rw ip=10.0.2.15::10.0.2.1:255.255.255.0 init=/sbin/init" -serial stdio -net nic,vlan=0 -net user,vlan=0,hostfwd=tcp:127.0.0.1:1234-:1234


hello: hello.c
	arm-none-linux-gnueabi-gcc $< -pg -o $@

rootfs: rcS hello
	mkdir -p $(ROOTFS_DIR)
	rsync -ru $(BUSYBOX_DIR)/ $(ROOTFS_DIR)/
	rsync -ru $(LIBC_DIR)/etc $(ROOTFS_DIR)/
	rsync -ru $(LIBC_DIR)/lib $(ROOTFS_DIR)/
	rsync -ru $(LIBC_DIR)/sbin $(ROOTFS_DIR)/
	rsync -ru $(LIBC_DIR)/usr $(ROOTFS_DIR)/
	mkdir -p $(ROOTFS_DIR)/proc
	mkdir -p $(ROOTFS_DIR)/sys
	mkdir -p $(ROOTFS_DIR)/dev
	mkdir -p $(ROOTFS_DIR)/etc/init.d
	rsync -u rcS $(ROOTFS_DIR)/etc/init.d/
	rsync -u hello $(ROOTFS_DIR)/usr/bin/

