#!/usr/bin/env python

from distutils.core import setup, Extension


module = Extension('_square',
                           sources=['square.cpp', 'square_wrap.cxx'],
                           )

setup (name = 'tutorial',
       version = '0.1',
       author      = "xx",
       description = """c++ classes""",
       ext_modules = [module],
       py_modules = ["tutorial"],
       )
