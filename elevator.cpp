#include "elevator.hpp"
#include "constants.hpp"

Elevator::Elevator(SpeedController *top, SpeedController *bottom,
                    Encoder *eTop, Encoder *eBottom,
                    DigitalInput *iTop, DigitalInput *iIn,
      	            DigitalInput *iEnter, int numOfBalls
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
	
	limboBall = false;
	
	while ( numOfBalls-- )
		newBall();
}

Elevator *Elevator::calculate(int ballAdjustment)
{	
	if (pos == pooping)
	{
		speed = -1;
		return this;
	}
	else if (pos == shooting)
	{
		speed = 1;
		return this;
	}
	if (calculateBalls(ballAdjustment)) return this;
	if (!ball1)
	{
		speed = 0;
	}
	else if (pos == drivePos)
	{
		//cerr<<"HEY! I GOT TO THE DRIVEPOS PART!"<<endl;
		if (iIn->Get()) 
		{
			speed = 0;
			//cerr << "Going down, not! iIn: " << iIn->Get() << endl;
		}
		else 
		{
			speed = -1;
			//cerr << "Going down!" << endl;
		}
	}
	else if (pos == shootPos)
	{
		if (iTop->Get()) speed = 0;
		else speed = 1;
	}
	else cerr << "[Elevator::calculate()] This should not be printed." << endl;
	return this;
}

Elevator *Elevator::update()
{
	//top->Set(speed);
	bottom->Set(-speed);
	
	//cerr << "SPEED: " << speed << endl;

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
	if (ball3) return;
	
	ball3 = ball2;
	ball2 = ball1;
	ball1 = new Ball(0);
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

Elevator::ElevatorPosition Elevator::getPosition()
{
	return pos;
}

Elevator *Elevator::setPosition(ElevatorPosition pos)
{
	this->pos = pos;
	return this;
}

bool Elevator::calculateBalls(int ballAdjustment)
{
	bool handled = false;

	bool iEnterOn = !iEnter->Get();
	bool iInOn = iIn->Get();
	bool iTopOn = iTop->Get();
	
	for(; ballAdjustment > 0; ballAdjustment--)
		newBall();
	
	for(; ballAdjustment < 0; ballAdjustment++)
		doShoot();
	//bool limboBallBefore = limboBall;
	if( iInOn && tIIn.Get() == 0)
	{
		tIIn.Start();
	}
	else if( !iInOn && tIIn.Get() > Constants::elevatorBallSpeediIn)
	{
		limboBall = false;
		handled = false; 
		//if(limboBallBefore)
			//cerr<<"Ball Has now Passed out of limbo"<<endl;
	}
	if( !iInOn )
	{
		tIIn.Stop();
		tIIn.Reset();
	}
	if( iEnterOn && tIEnter.Get() == 0)
	{
		tIEnter.Start();
	}
	else if( !iEnterOn && tIEnter.Get() > Constants::elevatorBallSpeediEnter)
	{
		if ( speed > 0 )
		{
			newBall();
		}
	}
	if( !iEnterOn )
	{
		tIEnter.Stop();
		tIEnter.Reset();
	}
	if ( iEnterOn || limboBall )
	{
		speed = 1;
		limboBall = true;
		handled = true;
		//if(!limboBallBefore)
			//cerr<<"Ball is now in limbo"<<endl;
	}
	iEnterOnBefore = iEnterOn;
	
	if( iTopOn && tITop.Get() == 0) // Ball was not previously in sensor.
	{
		tITop.Start();
	}
	else if( !iTopOn && tITop.Get() > Constants::elevatorBallSpeed ) 
	{ // Ball went through sensor.
		
		if ( speed > 0 )
		{
			cerr << tITop.Get() << endl;
			doShoot();
		}
	}
	
	if (!iTopOn)       // If the sensor is off,
	{
		tITop.Stop();  // Reset the timer.
		tITop.Reset(); //
	}
	
	return handled;
}

int Elevator::getNumOfBalls()
{
	if      (ball3 != NULL) return 3;
	else if (ball2 != NULL) return 2;
	else if (ball1 != NULL) return 1;
	else return 0;
}

Elevator* Elevator::setSpeed(int newSpeed)
{
	speed = newSpeed;
	return this;
}

Elevator* Elevator::setBalls(int newBalls)
{
	while(getNumOfBalls() > newBalls)
		doShoot();
	while(getNumOfBalls() < newBalls)
		newBall();
	return this;
}
