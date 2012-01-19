#include "elevator.hpp"

const static Elevator::ElevatorPosition drivePos;
const static Elevator::ElevatorPosition shootPos;

Elevator::Elevator(SpeedController *top, SpeedController *bottom,
                    Encoder *eTop, Encoder *eBottom,
                    DigitalInput *iTop, DigitalInput *iIn,
      	            DigitalInput *iEnter
                  )
{
	init();

	this->top     = top;
	this->bottom  = bottom;
	this->eTop    = eTop;
	this->eBottom = eBottom;
	this->iTop = iTop;
	this->iIn = iIn;
	this->iEnter = iEnter;
}

Elevator *Elevator::calculate()
{
	

	return this;
}

void Elevator::init()
{
	top = bottom = NULL;
	eTop = eBottom = NULL;
	iTop = iIn = iEnter = NULL;

	ball1 = ball2 = ball3 = NULL;
}

bool Elevator::isFull(void)
{
	if(ball3 != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Elevator* Elevator::shoot()
{
	return this;
}

Elevator* Elevator::shootPos()
{
	//not smart, look it over
	top->Set(move);
	bottom->Set(-move);
	return this;
}

Elevator* Elevator::pickUpPos()
{
	return this;
}

void Elevator::testSensor()
{
	fprintf(stderr, "%i", iIn->Get());
}

Elevator::ElevatorPosition Elevator::getPosition()
{
	return pos;
}

Elevator *Elevator::setPosition(Elevator::ElevatorPosition pos)
{
	this->pos = pos;
	return this;
}
