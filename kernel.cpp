// Coyright (c) Marc Puttkammer
// 

#include "multiboot.hpp"
#include "gdt.hpp"
#include "memory.hpp"
#include "video.hpp"

extern "C" void kernel_main( const multiboot& multiboot_structure, typ::uint32_t mboot_magic );

void kernel_main( const multiboot& /*multiboot_structure*/, typ::uint32_t mboot_magic ) {
  if( multiboot_magic != mboot_magic ) {
    screen << color_t( color::red, color::white )
      << "Error: No Multiboot Bootloader Found ( Err_NMBF )";
    return;
  }
  screen << color_t( color::white, color::black );
  screen.clear();
  screen << "Welcome OSDeveloper";
  screen.endl();  
  gdt::init_gdt();
  return;
}

