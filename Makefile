SRCS = $(shell find -name '*.c')
AS_SRCS = $(shell find -name '*.S')
ASM_SRCS = $(shell find -name '*.asm')
CXXS = $(shell find -name '*.cpp') 
OBJS = $(addsuffix .o,$(basename $(SRCS) $(CXXS) $(AS_SRCS) $(ASM_SRCS)))

INCS = -I./ -I./std/c -I./std/cpp -I/usr/lib/gcc/i686-elf/4.9.2/include/

ASM = nasm
CC = gcc
CXX = g++
LD = ld

DEFAULT_FLAGS?= -m32 -O2 -ggdb -Wall -Wextra -nostdinc -pedantic-errors -static-libgcc -lgcc -lsupc++ $(INCS)
DEFAULT_FLAGS:=$(DEFAULT_FLAGS) -fno-builtin -fno-exceptions -fno-leading-underscore -fno-stack-protector -ffreestanding

ASFLAGS = -f elf
CFLAGS = -std=c11
CXXFLAGS = -std=c++11 -fno-use-cxa-atexit -fno-rtti 
LDFLAGS = -melf_i386 -Tkernel.ld
kernel: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(DEFAULT_FLAGS) $(CFLAGS) -c -o $@ $^

%.o: %.cpp
	$(CXX) $(DEFAULT_FLAGS) $(CXXFLAGS) -c -o $@ $^

%.o: %.S
	$(CC) -m32 -c -o $@ $^

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $^

clean:
	rm $(OBJS)

complete_clean:
	rm $(OBJS) kernel

the_boot:
	bash -c ./boot.sh

the_debug:
	bash -c ./boot_debug.sh

.PHONY: clean the_boot the_debug complete_clean
