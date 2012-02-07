#include "elevator.hpp"
#include "constants.hpp"

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
		speed = 0;
	}
	else if (pos == drivePos)
	{
		if (iIn->Get() == 1) speed = 0;
		else speed = -1;
	}
	else if (pos == shootPos)
	{
		if (iTop->Get() == 1) speed = 0;
		else speed = 1;
	}
	else if(pos == shooting)
	{
		if(getNumOfBalls() > 0)speed = 1;
		else speed = 0;
	}
	else cerr << "[Elevator::calculate()] This should not be printed." << endl;
	return this;
}

Elevator *Elevator::update()
{
	Elevator->calculate();

	top->Set(speed);
	bottom->Set(speed);

	return this;
}

void Elevator::init(void)
{
	top = bottom = NULL;
	eTop = eBottom = NULL;
	iTop = iIn = iEnter = NULL;

	ball1 = ball2 = ball3 = NULL;
}

void Elevator::newBall (void)
{
	if      (!ball1) fprintf(stderr, "BALL 1\n");
	else if (!ball2) fprintf(stderr, "BALL 2\n");
	else if (!ball3) fprintf(stderr, "BALL 3\n");
	ball3 = ball2;
	ball2 = ball1;
	ball1 = new Ball(0);
	if      (!ball1) fprintf(stderr, "BALL 1\n\n");
	else if (!ball2) fprintf(stderr, "BALL 2\n\n");
	else if (!ball3) fprintf(stderr, "BALL 3\n\n");
	else cerr << "Too many balls." << endl;
}

Elevator *Elevator::doShoot ( void )
{
	if (ball3)
	{
		delete ball3;
		ball3 = NULL;
	}
	else if (ball2)
	{
		delete ball2;
		ball2 = NULL;
	}
	else if (ball1)
	{
		delete ball1;
		ball1 = NULL;
	}
	else cerr << "AHHH! can't shoot no balls!\nBeware of the ghost ball." << endl;
	return this;
}

bool Elevator::isFull(void)
{
	return ball3 != NULL;
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
	fprintf(stderr, "%d", iTop->Get());
}

Elevator::ElevatorPosition Elevator::getPosition()
{
	return pos;
}

Elevator *Elevator::setPosition(ElevatorPosition pos)
{
	this->pos = pos;
	return this;
}

Elevator *Elevator::calculateBalls()
{
	bool iEnterOn = iEnter->Get();
	bool iTopOn = iTop->Get();
	
	if (iEnterOn && !iEnterOnBefore)
	{
		this->pickUpBall();
	}
	iEnterOnBefore = iEnterOn;
	cerr << "\t Time is: " << tITop.Get() << "\n";
	if( iTopOn && !tITop.Get() == 0 )
	{
		tITop.Start();
	}
	else if( !iTopOn && tITop.Get() > Constants::elevatorBallSpeed )
	{
		if ( speed > 0 ) doShoot();
		
		tITop.Stop();
		tITop.Reset();
	}
	return this;
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
				this->newBall();
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

int Elevator::getNumOfBalls()
{
	if      (ball3 != NULL) return 3;
	else if (ball2 != NULL) return 2;
	else if (ball1 != NULL) return 1;
	else return 0;
}
