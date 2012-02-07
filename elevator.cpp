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
		speed = 0;
	}
	else if (ballsToShoot > 0)
	{
		speed = 1;
		rotateBalls();
	}
	else
	{
		if (pos == drivePos)
		{
			if (iIn == 1) speed = 0;
			else speed = -1;
		}
		else if (pos == shootPos)
		{
			if (iTop == 1) speed = 0;
			else speed = 1;
		}
	}
	else cerr << "[Elevator::calculate()] This should not be printed." << endl;
	return this;
}

Elevator *Elevator::update()
{
	if (iEnter) pickUpBall;
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

bool Elevator::pickUpBall()
{
	if (!isFull())
	{
		PickerUpper->reverseDirection();
		return false;
	}
	else
	{
		switch (pos)
		{
			case drivePos:
				newBall(); //should probably use iIn but couldn't find newBall() called anywhere
				//move elevator forward somehow with encoders?
				return true;
				break;
			case shootPos:
				pickUpPosition();
				return false;
				break;
		}
	}
}

void Elevator::newBall (void)
{
	Ball *b = new Ball(0);

	if      (!ball1) ball1 = b;
	else if (!ball2) ball2 = b;
	else if (!ball3) ball3 = b;
	else cerr << "Too many balls." << endl;
}

void Elevator::rotateBall ()
{
	ball1 = ball2;
	ball2 = ball3;
	ball3 = NULL;
}

bool Elevator::isFull(void)
{
	return ball3 != NULL;
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
