// Coyright (c) Marc Puttkammer
// 

#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

namespace mem {

template <typename Iterator, unsigned long long int N>
class iterator {
public:
  // lifecycle
  //
  iterator( Iterator* pos ) : begin_( pos ), pos_( begin_ ), 
    end_( begin_ + sizeof( Iterator ) * N ) {}
  iterator( const iterator& iter ) : begin_( iter.begin_ ),
    pos_( iter.pos_ ), end_( iter.end_ ) {}
  
  ~iterator() {}

  // operator overloading
  //
  iterator& operator++() { ++pos; return *this; }
  iterator operator++( int ) { 
    iterator tmp( *this ); operator++(); return tmp;
  }
  bool operator==( const iterator& rval ) { return pos_==rval.pos_; }
  bool operator!=( const iterator& rval ) { return pos_!=rval.pos_; }
  int& operator*() { return *pos_ }

private:
  Iterator* begin_;
  Iterator* pos_;
  Iterator* end_;
};

} // namespace mem

#endif // !_MEMORY_HPP_

