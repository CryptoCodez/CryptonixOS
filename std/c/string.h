// =====================================================================================
//
//       Filename:  string.h
//
//    Description:  C string library
//
//        Version:  1.0
//        Created:  03/27/2016 01:03:04 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Marc Puttkammer (MP), CryptoCodez@protonmail.com
//   Organization:  
//
// =====================================================================================

#ifndef _STRING_H_
#define _STRING_H_

#include <sys/cdefs.hpp>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int memcmp( const void*, const void*, size_t );                    /* ptr1, ptr2, size */
void* memcpy( void* __restrict, const void* __restrict, size_t );  /* dstptr, srcptr, size */
void* memmove( void*, const void*, size_t );                       /* dstptr, srcptr, size */
void* memset( void*, int, size_t );                                /* bufptr, value, size */
size_t strlen( const char* );                                      /* string */ 

#ifdef __cplusplus
}
#endif

#endif // ----- #ifndef _STRING_H_  ----- 

