#ifndef MYCLASS_HPP_
#define MYCLASS_HPP_

#include <string>
#include <ostream>

	/*!
	 * This is a simple 'hello world' class part of the autotools examples.
	 * 
	 * @author Martin Mann - http://www.bioinf.uni-freiburg.de/~mmann/
	 * 
	 */
	class MyClass
	{
		protected:
		
			  //! the home URL of this class
			std::string homeURL;
		
		public:
			
			  //! construction
			MyClass();
			
			  //! destruction
			virtual ~MyClass();
			
			  /*! 
			   * Says hello to the world and prints the message to the given
			   * stream.
			   * @param out the stream to write the message to
			   */
			void sayHello(std::ostream & out) const;
	};

#endif /*MYCLASS_HPP_*/
