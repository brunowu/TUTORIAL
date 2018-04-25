Generate
```bash
swig -c++ -python square.i
g++ -fpic -c square.hpp square_wrap.cxx -I/apps/python/3/include/python3.5m
g++ -shared square.hpp square_wrap.o -o _square.so
```

Install

```bash
python setup.py build_ext --inplace
```

```python
import square as sq
s=sq.SquareInt(4) #initial interger sq
s.area() #return 16
s.setSide(10) #set new side for sq
s.getSide(10) #get side = 10
###
s2=sq.SquareFloat(4.5) #initial float sq
s.area() #return 20.25
```

