#include "elevator.hpp"

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

Elevator *Elevator::update()
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
	//don't know if 1 is right, needs a value
	top->Set(1);
	bottom->Set(1);

	moving = 1;
	return this;
}

Elevator* Elevator::pickUpPos()
{
	//don't know if 1 is right, needs a value
	top->Set(-1);
	bottom->Set(-1);

	moving = 1;
	return this;
}

Elevator* Elevator::stopMoving() //don't know if it goes in periodic or continuous check. put in periodic.
{
	if ((moving != 0) && ((iTop->Get() == 1) || (iIn->Get() == 1)))
	{
		top->Set(0);
		bottom->Set(0);
		moving = 0;
	}
	return this;
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
