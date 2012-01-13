/** \file vector.h
    \brief Main header file
*/
#ifndef VECTOR_H___MATH_VECTOR_LIBRARY
#define VECTOR_H___MATH_VECTOR_LIBRARY

#include <iostream>

#define _USE_MATH_DEFINES
// _USE_MATH_DEFINES not working
#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401
#include <math.h>

class Vector
{
public:
	double x;
	double y;
	
private:

	/** \internal
		\brief Bring angle into range

		Changes the value of \a d to that of a co-terminal angle such that
		\c -Pi \c <= \c value \c <= \c Pi.

		\param a The angle.
		\return An angle co-terminal to \a that is within the range of \c Pi to \c -Pi.
	*/
	static double bir (double d);
	/** \internal
		\brief Set an angles zero north

		Offset an angle so that it's zero is "North".

		\param d Input angle ( with zero "East" ).
		\return Output angle ( with zero "North" ).
	*/
	static double azn (double d);
	/** \internal
		\brief Set an angles zero South

		Offset an angle so that it's zero is "East".

		\param d Input angle ( with zero "North" ).
		\return Output angle ( with zero "East" ).
	 */
	static double aze (double d);
	/**	\internal
		\brief Convert radians to degrees

		Converts angle \a rad form radians to degrees.

		\param rad An angle in radian measure to be converted to degrees
		\return The measure of \a rad in degrees.
	*/

public:	
	static double todeg (double d);
	/**	\internal
		\brief Convert degrees to radians

		Converts angle \a rad form degrees to radians.

		\param rad An angle in degree measure to be converted to radians
		\return The measure of \a rad in radians.
	*/
	static double torad (double d);

	/**
		How we should set our vector.
	 */
	enum vectorSetType
	{
		xy, ///< Using \a x and \a y cordinates.
		magdir, ///< Using \a magnitude and \a direction.
		magdirdeg, ///< Using \a magnitude and \a direction in degrees.
	};

	/// Default Constructor
	/**
		Creates a Vector object initlized to nothing. (x and y as zero).
	*/
	Vector(void);

	/// Copy Constructor
	/**
	 *	Copys the given vector
	 */
	Vector(Vector &v);

	/// Constructor
	/**
		Create a vector with preset values.

		\param t Style of creation.  This is a item of the enum #vectorSetType .
		\param a Dependant on \a t.
		\param b Dependant on \a t.
	*/
	Vector(Vector::vectorSetType t, double a, double b);
	/// Set a vector
	/**
		Set the vector values.

		\param t Style of creation.  This is a item of the enum #vectorSetType .
		\param a Dependant on \a t.
		\param b Dependant on \a t.
	*/
	void set(Vector::vectorSetType t, double a, double b);

	/// Get the x.
	/**
		Get the x value of the vector.

		\return The x value
	*/
	double getX ( void );
	
	/// Get the y.
	/**
		Get the y value of the vector.

		\return The y value
	*/
	double getY ( void );

	/// Get the magnitude.
	/**
		Get the magnitude of the vector.

		\return The magnitude.
	*/
	double getMagnitude(void) const;
	/// Set Magnitude
	/**
		Change the magnitude of the vector.  The direction is preserved.

		\param mag The new magnitude.
	*/
	void setMagnitude(double mag);
	/// Get the direction.
	/**
		Get the direction of the vector.

		\return The direction in radians.
	*/
	double getDirection(void) const;
	///	Set the direction.
	/**
		Change the direction of the vector.  The magnitude is preserved.

		\param dir The new direction in radians.
	*/
	void setDirection(double dir);
	/// Get the direction in degrees.
	/**
		Get the direction of the vector om degrees.

		\return The direction in degrees.
	*/
	inline double getDirectionDegrees(void) const;
	///	Set the direction in degrees.
	/**
		Change the direction of the vector in degrees.  The magnitude is preserved.

		\param dir The new direction in degrees.
	*/
	inline void setDirectionDegrees(double dir);
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
	double getOffset(const Vector &v, int dir = 0) const;
	///	Get the distance from another vector in degrees
	/**
	 *	See Vector::getOffset().
	 *
	 *	\param it The vector to compare to.
	 *	\param dir The direction to return. If \a dir is less than 0 the angle
	 *		will be negative (the clockwise distance between the two).  If \a
	 *		dir is greater than zero, the angle will be positive (the
	 *		counter-clockwise distance between the two).  If the \a dir is 0 or
	 *		omitted, the nearest angle will be returned.
	 */
	inline double getOffsetDegrees(const Vector &v, int dir = 0) const;
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
	double getOffset(double a, int dir = 0) const;
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
	inline double getOffsetDegrees(double a, int dir = 0) const;

	Vector	operator + (Vector) const;
	void	operator += (Vector);
	Vector operator - (Vector) const;
	void	operator -= (Vector);
	template <class T> Vector operator * (T) const;
	template <class T> void operator *= (T);
	template <class T> Vector operator / (T) const;
	template <class T> void operator /= (T);

	/// Report info about the vector.
	/**
		Designed for debugging.  Prints info about the vector.
	*/
	void info(void);
};

#include "vector-templatefunctions.hpp"

#ifdef HEADER_ONLY
	#include "vector.cpp"
#endif

#endif
