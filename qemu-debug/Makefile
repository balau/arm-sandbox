KERNEL = linux-2.6.35/arch/arm/boot/zImage
BUSYBOX_INSTALL_DIR = busybox-1.17.1/_install
LIBC_DIR = ~/CodeSourcery/Sourcery_G++_Lite/arm-none-linux-gnueabi/libc
HELLO = hello-2.6/src/hello

.PHONY: run all debug

all: $(KERNEL) rootfs.img.gz

run: $(KERNEL) rootfs.img.gz
	@echo Run inside guest prompt:
	@echo   gdbserver --multi 10.0.2.15:1234	
	qemu-system-arm -M versatilepb -kernel $(KERNEL) -initrd rootfs.img.gz -append "root=/dev/ram rdinit=/sbin/init" -redir tcp:1234::1234

debug:
	ddd --debugger "arm-none-linux-gnueabi-gdb -x hello-remote.gdb"

rootfs.img.gz: rcS $(HELLO)
	cd $(BUSYBOX_INSTALL_DIR) && mkdir -p dev lib proc sys etc/init.d
	cp $(LIBC_DIR)/lib/ld-linux.so.3 $(BUSYBOX_INSTALL_DIR)/lib/
	cp $(LIBC_DIR)/lib/libm.so.6 $(BUSYBOX_INSTALL_DIR)/lib/
	cp $(LIBC_DIR)/lib/libc.so.6 $(BUSYBOX_INSTALL_DIR)/lib/
	cp $(LIBC_DIR)/lib/libdl.so.2 $(BUSYBOX_INSTALL_DIR)/lib/
	cp $(LIBC_DIR)/lib/libgcc_s.so.1 $(BUSYBOX_INSTALL_DIR)/lib/
	cp $(LIBC_DIR)/usr/bin/gdbserver $(BUSYBOX_INSTALL_DIR)/usr/bin/
	cp $(HELLO) $(BUSYBOX_INSTALL_DIR)/usr/bin/
	cp rcS $(BUSYBOX_INSTALL_DIR)/etc/init.d/
	cd $(BUSYBOX_INSTALL_DIR);\
	find . | cpio -o --format=newc | gzip > ../../rootfs.img.gz
