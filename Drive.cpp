#include <iostream>
#include <math.h>

using namespace std;

#include "Drive.hpp"

Drive::Drive(SpeedController *left, SpeedController *right):
	left(left),
	right(right)
{
	init();
}

void Drive::init()
{
	this->flipped = false;

	leftCorrection = rightCorrection = 1;
}

Drive::~Drive()
{

}

void Drive::drive()
{
	double ls, rs; // Speed of the motors.

	ls = rs = velocity.y;

	ls += velocity.x;
	rs -= velocity.x;

	ls *= leftCorrection;
	rs *= rightCorrection;

	double scale = fabs(1/max(max(ls, rs), 1));
	
	ls *= scale;
	rs *= scale;

	left->Set(ls);
	right->Set(rs);
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
