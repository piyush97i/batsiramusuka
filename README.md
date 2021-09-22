# EwokOS
.Author

	Misa.Z misa.zhu@gmail.com

.About

	A microkernel os for learning operating system. 

.Environment & Tools

	Ubuntu Linux 16.04 with "qemu-system-arm","gcc-arm-none-eabi","gdb-arm-none-eabi"
	installed(can install by "apt")
	
.make and run

	"make run": run EwokOS; 
	  "qemu-system-arm -kernel build/EwokOS.bin -initrd build/initfs"
	  boot kernel file and load init ramdisk.

	"make debug": run EwokOS at debug server-mode;
	"make gdb": debug EwokOS (debug client-mode);

.commands 
	
	Most of commands are in 'sbin' directory, like:
	ls, ps, pwd, test ......

.Source code read-guide

	kernel/arm/boot.S
	kernel/src/kalloc.c
	kernel/src/mmu.c
	kernel/src/proc.c 
	kernel/src/sheduler.c
	kernel/src/syscalls.c
	kernel/src/kmessage.c

	lib/src/stdlib.c
	lib/src/unistd.c
	lib/src/pmessage.c

	sbin/init/init.c
	sbin/vfs/vfs.c
	sbin/shell/shell.c

	Tips: Don't fall in love with assembly too much;).

. Kernel init memory map

	PhyMem                         VMem
	0x00000000-0x00080000  map to  0x80000000-0x80080000  (8M)

	PhyMem        VMem         Desc
	----------------------------------------------------
	0x00000000    0xFFFF0000   interrupt table
	0x00010000    0x80010000   Kernel start (load to)
	***           ***          (_initStack, _irqStack, _startupPageDir)
	***           ***          Kernel end
	+1M           +1M          kernel malloc base
	+2M           +2M          kernel malloc end (size=2M).

	0x08000000    0x08000000   init ramdisk base (load initrd to)
	0x08010000    0x08010000   init ramdisk end (size=1M).

	MMIO_BASE_PHY MMIO_BASE    MMIO base (arch)



