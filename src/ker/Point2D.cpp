#ifndef POINT2D_CPP
#define POINT2D_CPP

#include "Point2D.hpp"

template<typename T>
Point2D<T>::Point2D(): x(), y()
{}

template<typename T>
Point2D<T>::Point2D(T x, T y): x(x), y(y)
{}

template<typename T>
Point2D<T>::Point2D(const Point2D<T> & p): x(p.x), y(p.y)
{}

template<typename T>
Point2D<T>::~Point2D()
{}

template<typename T>
Point2D<T> & Point2D<T>::operator+= (const Point2D<T> & p)
{
    x += p.x;
    y += p.y;
    return *this;
}

template<typename T>
Point2D<T> & Point2D<T>::operator-= (const Point2D<T> & p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

template<typename T>
Point2D<T> & Point2D<T>::operator*= (const T & r)
{
    x *= r;
    y *= r;
    return *this;
}

template<typename T>
Point2D<T> & Point2D<T>::operator= (const Point2D<T> & p)
{
    x = p.x;
    y = p.y;
    return *this;
}

template <typename T>
Point2D<T> operator+ (const Point2D<T> & p)
{
    return p;
}

template <typename T>
Point2D<T> operator- (const Point2D<T> & p)
{
    return Point2D<T>(-p.x, -p.y);
}

template <typename T>
Point2D<T> operator+ (const Point2D<T> & p, const Point2D<T> & q)
{
    return Point2D<T>(p.x+q.x, p.y+q.y);
}

template <typename T>
Point2D<T> operator- (const Point2D<T> & p, const Point2D<T> & q)
{
    return Point2D<T>(p.x-q.x, p.y-q.y);
}

template <typename T>
Point2D<T> operator* (const Point2D<T> & p, const T & r)
{
    return Point2D<T>(p.x*r, p.y*r);
}

template <typename T>
Point2D<T> operator* (const T & r, const Point2D<T> & p)
{
    return Point2D<T>(p.x*r, p.y*r);
}

template <typename T>
T operator| (const Point2D<T> & p, const Point2D<T> & q)
{
    return p.x*q.x + p.y*q.y;
}

template <typename T>
bool operator== (const Point2D<T> & p, const Point2D<T> & q)
{
    return p.x==q.x && p.y == q.y;
}

template <typename T>
bool operator!= (const Point2D<T> & p, const Point2D<T> & q)
{
    return p.x!=q.x || p.y != q.y;
}

#endif
