#include "Drive.hpp"
#include <math.h>

Drive::Drive(Motor *left, Motor *right):
	left(left),
	right(right)
{
	init();
}

void Drive::init()
{
	this->flipped = false;
}

Drive::~Drive()
{

}

void Drive::drive()
{
	double ls, rs; // Speed of the motors.

	ls = rs = velocity.y;

	ls -= velocity.x;
	rs += velocity.x;

	ls *= leftCorrection;
	rs *= rightCorrection;

	double scale = 1/max(ls, rs);

	ls *= scale;
	rs *= scale;

	left->Set(ls);
	right->set(rs);
}

Vector Drive::getVelocity()
{
	return velocity;
}

Drive *Drive::setVelocity(const Vector &velocity)
{
	this->velocity = velocity;

	return this;
}

Drive *Drive::setFlip(bool flip)
{
	this->flipped = flip;

	return this;
}

bool Drive::flip ( )
{
	return flipped = !flipped;
}

bool Drive::isFlipped()
{
	return flipped;
}
