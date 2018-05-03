
#include <iostream>

#include "mylib/myClass.hpp"

  /*!
   * A simple call binary for the example class within the autotools examples.
   * 
   * @author Martin Mann - http://www.bioinf.uni-freiburg.de
   * 
   */
int main(int argc, char ** argv) {
	
	  // create object of example class
	mylib::MyClass myObj;
	
	  // say hello to the user!
	myObj.sayHello(std::cout);
	
	return 0;
}
