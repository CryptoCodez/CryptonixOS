global loader
extern kernel_main
extern init_ctors

FLAGS equ 0
MAGIC equ 0x1badb002
CHECKSUM equ -(MAGIC + FLAGS)
section .text
align 4
multibootheader:
  dd MAGIC
  dd FLAGS
  dd CHECKSUM

loader:
  mov esp, 0x200000
  push eax
  push ebx
  call init_ctors
  call kernel_main

global gdt_flush
extern gp
gdt_flush:
  lgdt [gp]
  mov ax, 0x10
  mov ds, ax
  mov es, ax 
  mov fs, ax
  mov gs, ax
  mov ss, ax
  jmp 0x08: flush2

flush2:
  ret

stop:
  jmp stop
