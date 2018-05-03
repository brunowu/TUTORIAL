```bash
swig -c++ -python func.i
g++ -fpic -c func.hpp func_wrap.cxx -I/apps/python/3/include/python3.5m
g++ -shared func_wrap.o -o _func.so
```

