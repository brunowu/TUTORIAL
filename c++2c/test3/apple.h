#ifndef __APPLE_H__
#define __APPLE_H__

template<typename T>
class Apple
{
public:
    enum
    {
        APPLE_COLOR_RED,
        APPLE_COLOR_BLUE,
        APPLE_COLOR_GREEN,
    };

    Apple();
    T GetColor(void);
    void SetColor(T color);
private:
    T m_nColor;
};


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

#endif
