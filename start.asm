; Coyright (c) Marc Puttkammer
; 

extern kernel_main
extern init_ctors
global start
global gdt_flush
;mboot:
  PAGE_ALIGN equ 1<<0
  MEMORY_INFO equ 1<<1
;  AOUT_KLUDGE equ 1<<16
  MAGIC equ 0x1badb002
  FLAGS equ PAGE_ALIGN | MEMORY_INFO
  CHECKSUM equ -(MAGIC + FLAGS)
;  EXTERN code, end

section .text
align 4
multibootheader:
  dd MAGIC
  dd FLAGS
  dd CHECKSUM

;aoutkludge
;  dd mboot
;  dd code
;  dd end
;  dd start


start:
  mov esp, 0x200000
  push eax
  push ebx
  call init_ctors
  call kernel_main

stublet:
  jmp $

gdt_flush:
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
