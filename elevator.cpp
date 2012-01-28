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
	this->calculateBalls();
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
	else if (ballsToShoot == 0)
	{
		if (pos == drivePos)
		{
			if (iIn->Get() == 1) speed = 0;
			else speed = -1;
		}
		else if (pos == shootPos)
		{
			if (iTop->Get() == 1) speed = 0;
			else speed = 1;
		}
	}
	else cerr << "[Elevator::calculate()] This should not be printed." << endl;
	return this;
}

Elevator *Elevator::update()
{
	top->Set(speed);
	bottom->Set(speed);
	return this;
}

void Elevator::init()
{
	top = bottom = NULL;
	eTop = eBottom = NULL;
	iTop = iIn = iEnter = NULL;

	ball1 = ball2 = ball3 = NULL;
}

void Elevator::newBall (void)
{
	Ball *b = new Ball(0);

	if      (!ball1) {ball1 = b; fprintf(stderr, "BALL 1");}
	else if (!ball2) {ball2 = b; fprintf(stderr, "BALL 2");}
	else if (!ball3) {ball3 = b; fprintf(stderr, "BALL 3");}
	else cerr << "Too many balls." << endl;
}

void Elevator::rotateBalls ()
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
	fprintf(stderr, "%d", iEnter->Get());
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

Elevator *Elevator::calculateBalls()
{
	UINT32 iEnterOn = iEnter->Get();
	
	if (iEnterOn && !iEnterOnBefore)
	{
		this->newBall();
	}
	iEnterOnBefore = iEnterOn;
	
	return this;
}

int Elevator::getNumOfBalls()
{
	if (ball3 != NULL) return 3;
	else if (ball2 != NULL) return 2;
	else if (ball1 != NULL) return 1;
	else return 0;
}
