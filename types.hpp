// Coyright (c) Marc Puttkammer
// 

#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#define PACKED __attribute__((packed))

namespace typ {

using int8_t = char;
using int16_t = short;
using int32_t = int;
using int64_t = long long;

using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = unsigned long long;

using cint8_t = const char;
using cint16_t = const short;
using cint32_t = const int;
using cint64_t = const long long;

using size_t = long long int;

} // namespace typ

#endif // !TYPES_HPP_

