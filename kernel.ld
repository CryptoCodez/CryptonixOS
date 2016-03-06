ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS
{
    . = 0x00100000;

    .text : {
        *(multiboot)
        *(.text)
    }
    .data ALIGN(4096) : {
	start_ctors = .;
	KEEP(*(.init_array ));
	KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)));
	end_ctors = .;

        *(.data)
    }
    .rodata ALIGN(4096) : {
        *(.rodata)
    }
    .bss ALIGN(4096) : {
        *(.bss)
    }

}
