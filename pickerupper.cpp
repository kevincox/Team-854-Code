#include "pickerupper.hpp"

PickerUpper::PickerUpper(SpeedController *motor)
{
	speed = 0;
	this->motor = motor;
}

PickerUpper::~PickerUpper()
{
}

PickerUpper *PickerUpper::setDirection(bool forwards)
{
	if (forwards) this->goForwards();
	else          this->goBackwards();
	
	return this;
}

PickerUpper *PickerUpper::update()
{
	motor->Set(speed);
	
	return this;
}

void PickerUpper::setSpeed(double speed)
{
	this->speed = speed;
}

double PickerUpper::getSpeed()
{
	return speed;
}

PickerUpper *PickerUpper::goForwards()
{
	speed = Constants::PickerUpperForwardsSpeed;
	
	return this;
}

PickerUpper *PickerUpper::goBackwards()
{
	speed = Constants::PickerUpperBackwardsSpeed;
	
	return this;
}

bool PickerUpper::isForward()
{
	if (speed >= 0) return true;
	else            return false;
}
