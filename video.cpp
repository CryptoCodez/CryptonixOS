// Coyright (c) Marc Puttkammer
// 

#include "video.hpp"

video screen;

video::video() : m_videomem(( typ::uint16_t* ) 0xb8000 ), 
  m_off( 0 ), m_pos( 0 ), m_color(( typ::uint16_t ) 0x0700 ) {
  clear();
}

video::~video() {}

void video::clear() {
  for( int i { 0 }; i < ( 80 * 25 ); i++ )
    m_videomem[ i ] = ( typ::uint8_t )' ' | m_color;
  m_pos = 0;
  m_off = 0;
}

video& video::operator <<( const char* s ) {
  while( *s != '\0' )
    put( *s++ );
  return *this;
}

video& video::operator <<( const color_t& color ) {
  m_color = static_cast<typ::uint16_t>( color.background_ << 4) | ( color.foreground_ & 0x0F );
  return *this;
}

video& video::operator <<( typ::size_t size ) {
  int tmp { 0 };
  //while( size >= 10 ) {
    //tmp = size % 10;
    //size = size / 10;
    //switch( tmp ) {
    //case 0: put( '0' ); break;
    //case 1: put( '1' ); break;
    //case 2: put( '2' ); break;
    //case 3: put( '3' ); break;
    //case 4: put( '4' ); break;
    //case 5: put( '5' ); break;
    //case 6: put( '6' ); break;
    //case 7: put( '7' ); break;
    //case 8: put( '8' ); break;
    //case 9: put( '9' ); break;
    //default: break;
    //}
  //}
  return *this;
}

void video::put( char c ) {
  if( m_pos >= ( 80 * 25 ))
    clear();
  m_videomem[ m_off * 80 + m_pos ] = (( typ::uint16_t ) m_color << 8) | c;
  m_pos++;
}
