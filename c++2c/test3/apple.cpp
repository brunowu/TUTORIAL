#include "apple.h"

template<typename T>
Apple<T>::Apple():m_nColor(APPLE_COLOR_RED)
{
}

template<typename T>
void Apple<T>::SetColor(T color)
{
    m_nColor = color;
}

template<typename T>
T Apple<T>::GetColor(void)
{
    return m_nColor;
}
