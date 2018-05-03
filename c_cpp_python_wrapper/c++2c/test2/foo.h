#include <stdint.h>

#ifdef __cplusplus

#include <string>

template<typename T>
class Foo
{
 public:
    Foo( T a );
    ~Foo();
    std::string toString();
private:
   T k;
};

#endif
#ifdef __cplusplus
extern "C"
{
#endif

void*  getFoo( int32_t a );
void   destroyFoo( void *foo );
void   printString( void *foo );

#ifdef __cplusplus
}
#endif
