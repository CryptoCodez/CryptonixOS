// Coyright (c) Marc Puttkammer
// 

#include "types.hpp"

extern "C" void __cxa_pure_virtual(); // {}

typedef void( *constructor )();

extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void init_ctors();

void init_ctors() {
  for( constructor* i { &start_ctors }; i != &end_ctors; ++i )
    (*i)();
}

extern "C" {
  int __cxa_atexit( void ( *f )( void* ), void* p, void* d);
  void __cxa_finalize( void* d );
}

void *__dso_handle;

struct object {
  void ( *f )( void* );
  void *p;
  void *d; 
} object[ 32 ] = {};
typ::uint32_t iObject { 0 };

int __cxa_atexit( void ( *f )( void* ), void *p, void *d ) {
  if( iObject >= 32 ) return -1;
  object[ iObject ].f = f;
  object[ iObject ].p = p;
  object[ iObject ].d = d;
  ++iObject;
  return 0;
}

void __cxa_finalize( void *d ) {
  typ::uint32_t i { iObject };
  for( ; i > 0; --i ) {
    --iObject;
    object[ iObject].f( object[ iObject ].p );
  }
}

