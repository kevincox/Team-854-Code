#include "pickerupper.hpp"

PickerUpper::PickerUpper(SpeedController *motor)
{
	speed = 0;
	this->motor = motor;
}

PickerUpper::~PickerUpper()
{
}

PickerUpper *PickerUpper::reverseDirection(bool forwards)
{
	if (forwards) 		this->goForwards();
	else if (!forwards) this->goBackwards();
	else cerr << "IDK WHATS GOING ON WITH PICKERUPPER!!!" << endl;
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
	if(speed == 0)speed = Constants::PickerUpperForwardsSpeed;
	return this;
}

PickerUpper *PickerUpper::goBackwards()
{
	if(speed > 0)speed *= -1;
	if(speed == 0)speed = Constants::PickerUpperBackwardsSpeed;
	return this;
}

bool PickerUpper::isForward()
{
	if (speed >= 0) return true;
	else            return false;
}
