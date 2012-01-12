#include "Drive.hpp"

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
