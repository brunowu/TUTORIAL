%module square
%{
#include "square.hpp"
%}

%include "polygon.hpp"
%include "square.hpp"

%template(PolygonInt) Polygon<int>;
%template(SquareInt) Square<int>;

%template(PolygonFloat) Polygon<float>;
%template(SquareFloat) Square<float>;
