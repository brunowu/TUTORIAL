import ctypes

hello = ctypes.CDLL('/Users/xwu/phd_xwu/C-C-Python-Wapper-Learning/ctypes/c-example/hellolib.so')
hello.myprint()

