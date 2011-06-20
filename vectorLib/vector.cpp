#include "vector.hpp"

double Vector::bir (double a) const
{
	while ( a > M_PI )  a -= 2*M_PI;
	while ( a < -M_PI ) a += 2*M_PI;

	return a;
}

double Vector::azn (double d) const
{
	return bir(d - (M_PI/2));
}

double Vector::aze (double d) const
{
	return bir(d + (M_PI/2));
}

double Vector::todeg(double rad) const
{
	return rad*180/M_PI;
}

double Vector::torad(double deg) const
{
	return deg*M_PI/180;
}

Vector::Vector ( void ):
	x(0), y(0)
{ }

Vector::Vector ( Vector &v ):
x(v.x), y(v.y)
{ }

Vector::Vector(vectorSetType t, double a, double b)
{
	set(t, a, b);
}

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

double Vector::getMagnitude(void) const
{
	return sqrt(pow(x,2)+pow(y,2));
}

void Vector::setMagnitude(double mag)
{
	set(magdir, mag, getDirection());
}

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

void Vector::setDirection( double dir )
{
	set(magdir, getMagnitude(), dir);
}

double Vector::getDirectionDegrees ( ) const
{
	return todeg(getDirection());
}

void Vector::setDirectionDegrees ( double dir )
{
	setDirection(torad(dir));
}

inline double Vector::getOffset ( const Vector &v, int dir ) const
{
	return getOffset(v.getDirection(), dir);
}

double Vector::getOffset ( double it, int dir ) const
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

double Vector::getOffsetDegrees ( const Vector &v, int dir ) const
{
	return todeg(getOffset(v, dir));
}

double Vector::getOffsetDegrees ( double a, int dir ) const
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

void Vector::info()
{
	printf("(%lf,%lf) Magnitude: %lf Direction: %lf (%lf degrees)\n", x, y, getMagnitude(), getDirection(), getDirectionDegrees());
}
