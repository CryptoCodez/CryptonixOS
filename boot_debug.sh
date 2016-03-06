qemu-system-i386 -S -s -singlestep -kernel kernel -serial file:serial.log & uxterm -e "gdb -iex \"target remote 127.0.0.1:1234\" -iex \"symbol-file kernel\""
