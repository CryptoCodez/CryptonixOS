# CryptonixOS
##C++ Operating system

###Usage
    make  
    make the_boot # boot the kernel using qemu
    make the_debug # start qemu with gdb and load debugging symbol file
    make clean # clean only object files
    make complete_clean" # same as above, including kernel
<br/>
###Requirements:
* x86 cpu
* multiboot-loader ( like grub )

###Dev Requirements:
* qemu-system-i386,
* gdb,
* make,
* ld,
* nasm,
* gcc/ g++,
* uxterm ( or edit the boot scripts )
* vim ( recommended ;) )
