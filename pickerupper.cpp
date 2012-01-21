#include "pickerupper.h"

PickerUpper::PickerUpper(SpeedController *motor)
{
	speed = 0;
	this->motor = motor;
}

PickerUpper::~PickerUpper()
{

}

void PickerUpper::spin()
{
	motor->Set(speed);
}

void PickerUpper::reverseDirection()
{
	speed *= -1;
}

void PickerUpper::update(bool spin)
{
	if(spin) spin;
}

void PickerUpper::setSpeed(int speed)
{
	this->speed = speed;
}

double PickerUpper::getSpeed()
{
	return speed;
}
