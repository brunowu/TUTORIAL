# this is example-file: src/bin/Makefile.am

# additional include pathes necessary to compile the C++ programs
AM_CXXFLAGS = -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE PROGRAMS TO BUILD
###############################################################################

# the program to build (the names of the final binaries)
bin_PROGRAMS = helloWorld

# list of sources for the 'helloWorld' binary
helloWorld_SOURCES =	\
						helloWorld.cpp

# the additional libraries needed to link helloWorld
helloWorld_LDADD = 	$(top_builddir)/src/mylib/libmylib.a $(AM_LDFLAGS)

###############################################################################
