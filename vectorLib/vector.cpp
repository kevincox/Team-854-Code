#ifndef VECTOR_CPP___MATH_VECTOR_LIBRARY
#define VECTOR_CPP___MATH_VECTOR_LIBRARY

#include "vector.h"

/** \internal
	\brief Bring angle into range

	Changes the value of \a d to that of a co-terminal angle such that
	\c -Pi \c <= \c value \c <= \c Pi.

	\param a The angle.
	\return An angle co-terminal to \a that is within the range of \c Pi to \c -Pi.
*/
double Vector::bir (double a) const
{
	while ( a > M_PI )  a -= 2*M_PI;
	while ( a < -M_PI ) a += 2*M_PI;

	return a;
}
/** \internal
	\brief Set an angles zero north

	Offset an angle so that it's zero is "North".

	\param d Input angle ( with zero "East" ).
	\return Output angle ( with zero "North" ).
*/
double Vector::azn (double d) const
{
	return bir(d - (M_PI/2));
}

/** \internal
	\brief Set an angles zero South

	Offset an angle so that it's zero is "East".

	\param d Input angle ( with zero "North" ).
	\return Output angle ( with zero "East" ).
 */
double Vector::aze (double d) const
{
	return bir(d + (M_PI/2));
}

/**	\internal
	\brief Convert radians to degrees

	Converts angle \a rad form radians to degrees.

	\param rad An angle in radian measure to be converted to degrees
	\return The measure of \a rad in degrees.
*/
double Vector::todeg(double rad) const
{
	return rad*180/M_PI;
}

/**	\internal
	\brief Convert degrees to radians

	Converts angle \a rad form degrees to radians.

	\param rad An angle in degree measure to be converted to radians
	\return The measure of \a rad in radians.
*/
double Vector::torad(double deg) const
{
	return deg*M_PI/180;
}

/// Default Constructor
/**
	Creates a Vector object initlized to nothing. (x and y as zero).
*/
Vector::Vector() { x = 0; y = 0; };

/// Constructor
/**
	Create a vector with preset values.

	\param t Style of creation.  This is a item of the enum #vectorSetType .
	\param a Dependant on \a t.
	\param b Dependant on \a t.
*/
Vector::Vector(vectorSetType t, double a, double b)
{
	set(t, a, b);
}

/// Set a vector
/**
	Set the vector values.

	\param t Style of creation.  This is a item of the enum #vectorSetType .
	\param a Dependant on \a t.
	\param b Dependant on \a t.
*/
void Vector::set(vectorSetType t, double a, double b)
{
	switch (t)
	{
		case xy:
			x = a;
			y = b;
			break;
		case magdirdeg:
			b = torad(b);
		case magdir:
			b = bir(aze(b));
			x = a * cos(b);
			y = a * sin(b);
			break;
	}
}

/// Get the magnitude.
/**
	Get the magnitude of the vector.

	\return The magnitude.
*/
double Vector::getMagnitude(void) const
{
	return sqrt(pow(x,2)+pow(y,2));
}

/// Set Magnitude
/**
	Change the magnitude of the vector.  The direction is preserved.

	\param mag The new magnitude.
*/
void Vector::setMagnitude(double mag)
{
	set(magdir, mag, getDirection());
}

/// Get the direction.
/**
	Get the direction of the vector.

	\return The direction in radians.
*/
double Vector::getDirection(void) const
{
	double r;

	if ( x == 0 ) // On the x-axis
	{
		if ( y >= 0 ) r = M_PI_2; // Straight up
		else if ( y < 0 ) r = -M_PI_2; // Straight down
	}
	else if ( y == 0) // On the y-axis
	{
		if ( x > 0 ) r = 0;
		else if ( x < 0 ) r = M_PI;
	}
	else if ( x > 0 && y > 0 ) r = atan(y/x);
	else if ( x < 0 && y > 0 ) r = M_PI + atan(y/x);
	else if ( x > 0 && y < 0 ) r = atan(y/x);
	else if ( x < 0 && y < 0 ) r = -M_PI + atan(y/x);

	return bir(azn(r));
}

///	Set the direction.
/**
	Change the direction of the vector.  The magnitude is preserved.

	\param dir The new direction in radians.
*/
void Vector::setDirection(double dir)
{
	set(magdir, getMagnitude(), dir);
}

/// Get the direction in degrees.
/**
	Get the direction of the vector om degrees.

	\return The direction in degrees.
*/
double Vector::getDirectionDegrees() const
{
	return todeg(getDirection());
}

///	Set the direction in degrees.
/**
	Change the direction of the vector in degrees.  The magnitude is preserved.

	\param dir The new direction in degrees.
*/
void Vector::setDirectionDegrees(double dir)
{
	setDirection(torad(dir));
}


///	Get the distance from another vector
/**
	Finds the distance from one vector to another. This has nothing to do with
	the magnitude.

	This just calls Vector::getOffest with the angle from \a v

	\param v The vector to compare to.
	\param dir The direction to return. If \a dir is less than 0 the angle will
		be negative	(the clockwise distance between the two).  If \a dir is
		positive, the angle	will be positive (the counter-clockwise	distance
		between the two).  If the \a dir is 0 or omitted, the nearest angle will
		be returned.
*/
inline double Vector::getOffset(Vector v, float dir = 0 ) const
{
	return getOffset(v.getDirection(), dir);
}

///	Get the distance from another vector
/**
	Finds the distance from one vector to an angle.  The returned direction is
	dependant on \a dir.

	\note If \a dir is 0 and the angles are exactly \c Pi apart, this function
		will return the postive value.

	\param it The angle to compare to.
	\param dir The direction to return. If \a dir is less than 0 the angle will
		be negative	(the clockwise distance between the two).  If \a dir is
		positive, the angle	will be positive (the counter-clockwise	distance
		between the two).  If the \a dir is 0 or omitted, the nearest angle will
		be returned.
*/
double Vector::getOffset(double it, float dir = 0 ) const
{
	double us = getDirection();

	if ( us == it )

	while ( us < 0 ) us += 2*M_PI;
	while ( it < 0 ) it += 2*M_PI;

	double diff = it - us;
	if ( dir == 0 )
	{
		if ( diff <= M_PI ) return diff;            // This is closer
		else                return diff - (2*M_PI); // The negative co-terminal angle is closer
	}
	else if ( dir > 0 ) // They want a postive angle
	{
		return diff;
	}
	else // They want a negative angle
	{
		return diff - (2*M_PI);
	}
}

///	Get the distance from another vector in degrees
/**
	See Vector::getOffset().

	\param it The vector to compare to.
	\param dir The direction to return. If \a dir is less than 0 the angle will
		be negative	(the clockwise distance between the two).  If \a dir is
		positive, the angle	will be positive (the counter-clockwise	distance
		between the two).  If the \a dir is 0 or omitted, the nearest angle will
		be returned.
*/
inline double Vector::getOffsetDegrees(Vector v, float dir = 0 ) const
{
	return todeg(getOffset(v, dir));
}

///	Get the distance from another vector in degrees
/**
	See Vector::getOffset().

	\param it The angle to compare to.
	\param dir The direction to return. If \a dir is less than 0 the angle will
		be negative	(the clockwise distance between the two).  If \a dir is
		positive, the angle	will be positive (the counter-clockwise	distance
		between the two).  If the \a dir is 0 or omitted, the nearest angle will
		be returned.
*/
inline double Vector::getOffsetDegrees(double a, float dir = 0 ) const
{
	return todeg(getOffset(a, dir));
}

Vector	Vector::operator+ (Vector v) const
{
	Vector r(xy, x+v.x, y+v.y); return r;
}

void Vector::operator+= (Vector v)
{
	x += v.x;
	y += v.y;
}

Vector Vector::operator- (Vector v) const
{
	Vector r(xy, x - v.x, y - v.y);
	return r;
}

void Vector::operator-= (Vector v)
{
	x -= v.x;
	y -= v.y;
}

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

/// Report info about the vector.
/**
	Designed for debugging.  Prints info about the vector.
*/
void Vector::info()
{
	printf("(%lf,%lf) Magnitude: %lf Direction: %lf (%lf degrees)\n", x, y, getMagnitude(), getDirection(), getDirectionDegrees());
}

#endif
