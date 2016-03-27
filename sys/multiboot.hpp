// Coyright (c) Marc Puttkammer
// 

#ifndef _MULTIBOOT_HPP_
#define _MULTIBOOT_HPP_

#include "types.hpp"

using typ::uint32_t;
using typ::uint16_t;

enum { multiboot_magic =  0x2badb002 };

struct multiboot_header {
  const uint32_t magic { multiboot_magic };
  uint32_t flags;
  uint32_t checksum { -( magic + flags )};
  uint32_t header_addr;
  uint32_t load_addr;
  uint32_t load_end_addr;
  uint32_t bss_end_addr;
  uint32_t entry_addr;
  uint32_t mode_type;
  uint32_t mode_width;
  uint32_t mode_height;
  uint32_t mode_depth;
} PACKED;

struct multiboot {
  uint32_t flags;
  uint32_t mem_lower;
  uint32_t mem_upper;
  uint32_t bootdevice;
  uint32_t cmdline;
  uint32_t mods_count;
  uint32_t mods_address;
  uint32_t syms[4];
  uint32_t mmap_length;
  uint32_t mmap_addr;
  uint32_t drives_length;
  uint32_t drives_addr;
  uint32_t config_table;
  uint32_t boot_loader_name;
  uint32_t apm_table;
  uint32_t vbe_control_info;
  uint32_t vbe_mode_info;
  uint16_t vbe_mode;
  uint16_t vbe_interface_seg;
  uint16_t vbe_interface_off;
  uint16_t vbe_interface_len;
} PACKED;

#endif // !_MULTIBOOT_HPP_

