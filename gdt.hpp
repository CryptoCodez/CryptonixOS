#ifndef _GDT_HPP_
#define _GDT_HPP_

#include "types.hpp"

extern "C" void gdt_flush();

struct gdt_ptr {
  uint16_t limit;
  uint32_t base;
} PACKED;

struct gdt_ptr gp;

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

struct gdt_entry {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t granularity;
  uint8_t base_high;
} PACKED;

#define GDT_SIZE 5

struct gdt_entry gdt[ GDT_SIZE ];

/* static void set_entry( int i, uint32_t base, uint32_t limit, int flags ) {
  gdt[ i ] = limit & 0xffffL;

  gdt[ i ] |= ( base & 0xffffffL ) << 16;
  gdt[ i ] |= ( flags & 0xffLL ) << 40;
  gdt[ i ] |= (( limit >> 16 ) & 0xfL ) << 48;
  gdt[ i ] |= (( flags >> 8 ) & 0xffL ) << 52;
  gdt[ i ] |= (( base >> 24 ) & 0xffL ) << 56;
} */

void gdt_set_gate( int i, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran ) {
  gdt[ i ].base_low = ( base & 0xFFFF );
  gdt[ i ].base_middle = ( base >> 16 ) & 0xFF;
  gdt[ i ].base_high = ( base >> 24 ) & 0xFF;
  gdt[ i ].limit_low = ( limit & 0xFFFF );
  gdt[ i ].granularity = (( limit >> 16 ) & 0x0F );
  gdt[ i ].granularity |= ( gran & 0xF0 );
  gdt[ i ].access = access;
}

void gdt_install() {
  gp.limit = ( sizeof( struct gdt_entry ) * GDT_SIZE ) -1;
  gp.base = ( uint32_t )&gdt;
  gdt_set_gate( 0, 0, 0, 0, 0 );
  gdt_set_gate( 1, 0, 0xFFFFFFFF, 0x9A, 0xCF );
  gdt_set_gate( 2, 0, 0xFFFFFFFF, 0x92, 0xCF );
 
  gdt_flush();
}

/* void init_gdt() {
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

  gdt_flush();
} */

} // namespace gdt

#endif // !_GDT_HPP_


