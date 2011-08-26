KERNEL = zImage
ROOTFS_DIR = /srv/nfs/francesco/rootfs
BUSYBOX_DIR = ./_install

.PHONY: run rootfs

run: $(KERNEL) rootfs
	#../qemu-0.12.5/arm-softmmu/
	qemu-system-arm -M versatilepb -m 128 -kernel $(KERNEL) -append "root=/dev/nfs rw nfsroot=10.0.2.2:/srv/nfs/francesco/rootfs/ ip=10.0.2.15::10.0.2.1:255.255.255.0" -serial stdio

rootfs: rcS inittab
	mkdir -p $(ROOTFS_DIR)
	rsync -rul $(BUSYBOX_DIR)/ $(ROOTFS_DIR)/
	mkdir -p $(ROOTFS_DIR)/proc
	mkdir -p $(ROOTFS_DIR)/sys
	mkdir -p $(ROOTFS_DIR)/dev
	mkdir -p $(ROOTFS_DIR)/etc/init.d
	rsync -ul rcS $(ROOTFS_DIR)/etc/init.d/
	rsync -ul inittab $(ROOTFS_DIR)/etc/

