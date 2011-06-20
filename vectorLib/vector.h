/** \file vector.h
    \brief Main header file
*/

#ifndef VECTOR_H___MATH_VECTOR_LIBRARY
#define VECTOR_H___MATH_VECTOR_LIBRARY

#include <iostream>
#include <stdint.h>

#define _USE_MATH_DEFINES
#include <math.h>

class Vector
{
	double bir (double d) const;
	double azn (double d) const;
	double aze (double d) const;
	double torad (double d) const;
	double todeg (double d) const;

public:
	double x;
	double y;

	/**
		How we should set our vector.
	 */
	enum vectorSetType
	{
		xy, ///< Using \a x and \a y cordinates.
		magdir, ///< Using \a magnitude and \a direction.
		magdirdeg, ///< Using \a magnitude and \a direction in degrees.
	};
	Vector();

	Vector(Vector::vectorSetType, double, double);
	void set(Vector::vectorSetType, double, double);

	double getMagnitude(void) const;
	void setMagnitude(double);
	double getDirection(void) const;
	void setDirection(double);
	inline double getDirectionDegrees(void) const;
	inline void setDirectionDegrees(double);
	double getOffset(Vector, float) const;
	inline double getOffsetDegrees(Vector, float) const;
	double getOffset(double, float) const;
	inline double getOffsetDegrees(double, float) const;

	Vector	operator + (Vector) const;
	void	operator += (Vector);
	Vector operator - (Vector) const;
	void	operator -= (Vector);
	template <class T> Vector operator * (T) const;
	template <class T> void operator *= (T);
	template <class T> Vector operator / (T) const;
	template <class T> void operator /= (T);

	void info();
};

using namespace std;
ostream& operator << (ostream& os, Vector v)
{
	os << "(" << v.x << ", " << v.y << ")";
	os << " Magnitude: " << v.getMagnitude();
	os << " Direction: " << v.getDirection();
	os << " (" << v.getDirectionDegrees() << " degrees)" << endl;

	return os;
}

#include "vector.cpp"
#endif
