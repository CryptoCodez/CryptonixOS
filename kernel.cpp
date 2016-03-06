#include "video.hpp"
#include "multiboot.hpp"
#include "gdt.hpp"

extern "C" void kernel_main( const multiboot& multiboot_structure, uint32_t multiboot_magic );

void kernel_main( const multiboot& /*multiboot_structure*/, uint32_t multiboot_magic ) {
  if( multiboot_magic != MULTIBOOT_MAGIC ) {
    screen << color_t( color::red, color::white )
      << "Error: No Multiboot Bootloader Found ( Err_NMBF )";
    return;
  }
  screen << color_t( color::black, color::light_green ) << "Welcome OSDeveloper";
  
  gdt::gdt_install();
  screen << "gdt works";
  return;
}

