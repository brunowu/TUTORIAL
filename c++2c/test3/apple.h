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
#endif
