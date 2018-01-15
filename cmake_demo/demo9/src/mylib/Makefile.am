# this is example-file: src/mylib/Makefile.am

# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libmylib.a

# where to install the headers on the system
libmylib_adir = $(includedir)/mylib

# the list of header files that belong to the library (to be installed later)
libmylib_a_HEADERS =	\
						myClass.hpp 

# the sources to add to the library and to add to the source distribution
libmylib_a_SOURCES =	\
						$(libmylib_a_HEADERS) \
						myClass.cpp 
						
###############################################################################
