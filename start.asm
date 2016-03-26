; Coyright (c) Marc Puttkammer
; 

;mboot:
  PAGE_ALIGN equ 1<<0
  MEMORY_INFO equ 1<<1
;  AOUT_KLUDGE equ 1<<16
  MAGIC equ 0x1badb002
  FLAGS equ PAGE_ALIGN | MEMORY_INFO
  CHECKSUM equ -(MAGIC + FLAGS)
;  EXTERN code, end

section .bootstrap_stack, nobits
align 4
stack_bottom:
resb 16384
stack_top:

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

global start
start:
  mov esp, stack_top
  push eax
  push ebx
  extern init_ctors
  call init_ctors
  extern kernel_main
  call kernel_main
  cli
 
.hang:
  hlt
  jmp .hang

stublet:
  jmp $

global gdt_flush
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
