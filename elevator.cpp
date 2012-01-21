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

Elevator *Elevator::calculate()
{
	if (!ball1)
	{
		ballsToShoot = 0;
		canve
	}

	if (ballsToShoot)
}

Elevator *Elevator::update()
{
	Elevator->calculate();

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

Elevator* Elevator::shoot(int numBalls)
{
	ballsToShoot += numBalls;
	return this;
}

Elevator* Elevator::shootPosition()
{
	pos = shootPos;
	return this;
}

Elevator* Elevator::pickUpPosition()
{
	pos = drivePos;
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


void Elevator::testSensor()
{
	fprintf(stderr, "%d", iIn->Get());
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
