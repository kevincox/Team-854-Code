#include "pickerupper.hpp"

PickerUpper::PickerUpper(SpeedController *motor)
{
	speed = 0;
	this->motor = motor;
}

PickerUpper::~PickerUpper()
{
}

PickerUpper *PickerUpper::reverseDirection(bool forwards, bool backwards)
{
	if(!(forwards&&backwards)&& forwards)this->goForwards();
	else if(!(forwards&&backwards)&& backwards)this->goBackwards();
	update();
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
	if(speed < 0)speed *= -1;
	if(speed == 0)speed = constants.PickerUpperForwardsSpeed;
	return this;
}

PickerUpper *PickerUpper::goBackwards()
{
	if(speed > 0)speed *= -1;
	if(speed == 0)speed = constants.PickerUpperBackwardsSpeed;
	return this;
}

bool PickerUpper::isForward()
{
	if (speed >= 0) return true;
	else            return false;
}
