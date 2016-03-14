SRCS = $(shell find -name '*.c')
AS_SRCS = $(shell find -name '*.S')
ASM_SRCS = $(shell find -name '*.asm')
CXXS = $(shell find -name '*.cpp') 
OBJS = $(addsuffix .o,$(basename $(SRCS) $(CXXS) $(AS_SRCS) $(ASM_SRCS)))

ASM = nasm
CC = gcc
CXX = g++
LD = ld

ASFLAGS = -f elf
CFLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wall -Wextra -pedantic-errors -ggdb -fno-stack-protector -nostdinc -std=c11
CXXFLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wall -Wextra -pedantic-errors -ggdb -fno-stack-protector -nostdinc -std=c++11
LDFLAGS = -melf_i386 -Tkernel.ld
kernel: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

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
