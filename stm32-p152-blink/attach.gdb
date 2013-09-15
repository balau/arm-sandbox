target remote | openocd -f c232hm-edhsl-0.cfg -f stm32l.cfg -f gdb-pipe.cfg
monitor halt
monitor gdb_sync
stepi

