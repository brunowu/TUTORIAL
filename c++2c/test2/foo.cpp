  #include <iostream>
  #include <sstream>
  #include <iomanip>
  #include <stdint.h>

  #include "foo.h"

template<typename T>
Foo<T>::Foo( T a )
 {
    k = a << 1;
 }

template<typename T>
Foo<T>::~Foo()
 {
    /* don't really need to do anything here */
    /* k = 0 only for example purposes       */
    k = 0;
 }

template<typename T>
std::string
Foo<T>::toString()
 {
    std::ostringstream os;
    os << "Foo is currently: " << this->k << std::endl;
    return( os.str() );
}

void*
getFoo( int32_t a )
 {
      Foo<int32_t> *out( new Foo<int32_t>(a) );
      return( reinterpret_cast< void* >( out ) );
 }

 void
 destroyFoo( void* foo )
 {
    delete( reinterpret_cast< Foo<int32_t>* >( foo ) );
}

void
printString( void *foo )
{
    std::string s = reinterpret_cast< Foo<int32_t>* >( foo )->toString();
    std::cout << s;
}
