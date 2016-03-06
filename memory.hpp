#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

namespace mem {

void *operator new( size_t size ) {
  return kcalloc( size );
}

void *operator new[]( size_t size ) {
  return kcalloc( size );
}

void operator delete( void *obj ) {
  kfree( obj );
}

void operator delete[]( void *obj ) {
  kfree( obj );
}

} // namespace mem

#endif // !_MEMORY_HPP_

