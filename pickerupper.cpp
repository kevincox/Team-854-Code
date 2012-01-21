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

}

void PickerUpper::reverseDirection()
{
	speed *= -1;
}

void PickerUpper::update()
{

}
