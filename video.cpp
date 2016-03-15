// Coyright (c) Marc Puttkammer
// 

#include "video.hpp"

video screen;

video::video() : m_videomem(( uint16_t* ) 0xb8000 ), 
  m_off( 0 ), m_pos( 0 ), m_color(( uint16_t ) 0x0700 ) {
  clear();
}

video::~video() {}

void video::clear() {
  for( int i { 0 }; i < ( 80 * 25 ); i++ )
    m_videomem[ i ] = ( uint8_t )' ' | m_color;
  m_pos = 0;
  m_off = 0;
}

video& video::operator <<( const char* s ) {
  while( *s != '\0' )
    put( *s++ );
  return *this;
}

video& video::operator <<( const color_t& color ) {
  m_color = static_cast<uint16_t>( color.background_ << 4) | ( color.foreground_ & 0x0F );
  return *this;
}

void video::put( char c ) {
  if( m_pos >= ( 80 * 25 ))
    clear();
  m_videomem[ m_off * 80 + m_pos ] = (( uint16_t ) m_color << 8) | c;
  m_pos++;
}
