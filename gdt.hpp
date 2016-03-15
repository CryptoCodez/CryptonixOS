// Coyright (c) Marc Puttkammer
// 
#ifndef _GDT_HPP_
#define _GDT_HPP_

#include "types.hpp"
extern "C" void gdt_flush();

namespace gdt {

enum gdt_flags {
  dataseg = 0x02,
  codeseg = 0x0a,
  tss = 0x09,
  segment = 0x10,
  ring_0 = 0x00,
  ring_3 = 0x60,
  present = 0x80,
  f_4k_gran = 0x800,
  f_32_bit = 0x400,
};

const int GDT_ENTRIES { 5 };
static uint64_t gdta[ GDT_ENTRIES ];

struct gdt_ptr_{
  uint16_t limit;
  void* ptr;
  gdt_ptr_( uint64_t* p ) : limit( GDT_ENTRIES * 8 - 1 ), ptr( p ) {};
} PACKED;
using gdt_ptr = struct gdt_ptr_;

static void set_entry( int i, uint32_t base, uint32_t limit, int flags ) {
  gdta[ i ] = ( limit & 0xffffLL );
  gdta[ i ] |= ( base & 0xffffffLL ) << 16;
  gdta[ i ] |= ( flags & 0xffLL ) << 40;
  gdta[ i ] |= (( limit >> 16 ) & 0xfLL ) << 48;
  gdta[ i ] |= (( flags >> 8 ) & 0xffLL ) << 52;
  gdta[ i ] |= (( base >> 24 ) & 0xffLL ) << 56;
}

void init_gdt() {
  gdt_ptr gp( gdta );
  set_entry( 0, 0, 0, 0 );
  set_entry( 1, 0, 0xFFFF, gdt_flags::segment | gdt_flags::f_32_bit |
    gdt_flags::codeseg | gdt_flags::f_4k_gran | gdt_flags::present );
  set_entry(2, 0, 0xfffff, gdt_flags::segment | gdt_flags::f_32_bit |
    gdt_flags::dataseg | gdt_flags::f_4k_gran | gdt_flags::present );
  set_entry(3, 0, 0xfffff, gdt_flags::segment | gdt_flags::f_32_bit |
    gdt_flags::codeseg | gdt_flags::f_4k_gran | gdt_flags::present | 
    gdt_flags::ring_3 );
  set_entry(4, 0, 0xfffff, gdt_flags::segment | gdt_flags::f_32_bit |
    gdt_flags::dataseg | gdt_flags::f_4k_gran | gdt_flags::present | 
    gdt_flags::ring_3 );

  //asm volatile("lgdt %0" : : "m" (gp));
  gdt_flush();
}

} // namespace gdt

#endif // !_GDT_HPP_

