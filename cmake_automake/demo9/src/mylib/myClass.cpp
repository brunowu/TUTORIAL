#include "mylib/myClass.hpp"

namespace mylib {

	MyClass::
	MyClass()
		: homeURL("http://www.bioinf.uni-freiburg.de/~mmann/")
	{
	}
	
	MyClass::
	~MyClass()
	{
	}
	
	void
	MyClass::
	sayHello( std::ostream & out ) const 
	{
		out	<<"\n\tHello world, I am the example Program!\n\n"
				"\tI am part of the autotools examples by Martin Mann.\n\n"
			<<"\t" <<homeURL <<"\n"
			<<std::endl; 
	}

} // namespace mylib
