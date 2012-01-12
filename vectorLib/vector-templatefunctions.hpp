#ifndef VECTOR_TEMPLATEFUNCTIONS_HPP___MATH_VECTOR_LIBRARY
#define	VECTOR_TEMPLATEFUNCTIONS_HPP___MATH_VECTOR_LIBRARY

#include "vector.hpp"

template <class T> Vector Vector::operator * (T m) const
{
	Vector r(xy, x * m, y * m);
	return r;
}

template <class T> void Vector::operator *= (T m)
{
	x *= m;
	y *= m;
}

template <class T> Vector Vector::operator / (T m) const
{
	Vector r(xy, x / m, y / m);
	return r;
}

template <class T> void Vector::operator /= (T m)
{
	x /= m;
	y /= m;
}

#endif
