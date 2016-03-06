#ifndef _VIDEO_HPP_
#define _VIDEO_HPP_

#include "types.hpp"

namespace color {
  enum type {
    black = 0x00,
    blue = 0x01,
    green = 0x02,
    cyan = 0x03,
    red = 0x04,
    magenta = 0x05,
    brown = 0x06,
    light_gray = 0x07,
    dark_gray = 0x08,
    light_blue = 0x09,
    light_green = 0x0A,
    light_cyan = 0x0B,
    light_red =  0x0C,
    light_magenta = 0x0D,
    yellow = 0x0E,
    white = 0x0F,
  };
} // namespace color

struct color_t {
  inline color_t( color::type background, color::type foreground ) : 
   background_( background ), foreground_( foreground ) {}
  color::type background_;
  color::type foreground_;
};

class video {
public:
  video();
  ~video();
  void clear();
  video& operator <<( const char* s );
  video& operator <<( const color_t& color );
  void put( char c );

private:
  uint16_t* m_videomem;
  uint32_t m_off; // cursor y-pos
  uint32_t m_pos; // x-pos
  uint16_t m_color;
};

extern video screen;

#endif // !_VIDEO_HPP_

