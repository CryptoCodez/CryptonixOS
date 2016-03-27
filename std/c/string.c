// =====================================================================================
//
//       Filename:  string.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  03/27/2016 01:45:09 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Marc Puttkammer (MP), CryptoCodez@protonmail.com
//   Organization:  
//
// =====================================================================================

#include <string.h>

int memcmp( const void* ptr1, const void* ptr2, size_t size) {
  const unsigned char* ptra = ( const unsigned char* ) ptr1;
  const unsigned char* ptrb = ( const unsigned char* ) ptr2;
  for( size_t i = 0; i < size; i++ ) {
    if( ptra[ i ] < ptrb[ i ] ) return -1;
    else if( ptrb[ i ] < ptra[ i ] ) return 1;
  }
  return 0;
}

void* memcpy( void* __restrict dstptr, const void* __restrict srcptr, size_t size ) {
  unsigned char* dst = ( unsigned char* ) dstptr;
  const unsigned char* src = ( const unsigned char* ) srcptr;
  for( size_t i = 0; i < size; i++ ) dst[ i ] = src[ i ];
  return dstptr;
}

void* memmove( void* dstptr, const void* srcptr, size_t size ) {
  unsigned char* dst = ( unsigned char * ) dstptr;
  const unsigned char* src = ( const unsigned char* ) srcptr;
  if( dst < src ) { 
    for( size_t i = 0; i < size; i++ )
      dst[ i ] = src[ i ];
  } else {
    for( size_t i = size; i != 0; i-- )
      dst[ i - 1 ] = src[ i - 1 ];
  }
  return dstptr;
}

void* memset( void* bufptr, int value, size_t size ) {
  unsigned char* buf = ( unsigned char* ) bufptr;
  for( size_t i = 0; i < size; i++ ) buf[ i ] = ( unsigned char ) value;
  return bufptr;
}

size_t strlen( const char* string ) {
  size_t result = 0;
  while( string[ result ] ) result++;
  return result;
}

