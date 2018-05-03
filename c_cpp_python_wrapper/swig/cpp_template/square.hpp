#include "polygon.hpp"

template <class T>
class Square : public Polygon<T> {
public:
    T side;
    Square(T s);
    void setSide(T s);
    T getSide();
    T area();
};

template <class T>
Square<T>::Square(T s) {
    this->side = s;
}

template <class T>
void Square<T>::setSide(T s) {
    this->side = s;
}

template <class T>
T Square<T>::getSide() {
    return this->side;
}

template <class T>
T Square<T>::area() {
    return this->side * this->side;
}

