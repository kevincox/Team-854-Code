#include "elevator.hpp"

Elevator::Elevator(SpeedController *top, SpeedController *bottom,
                    Encoder *eTop, Encoder *eBottom
                  )
{
	init();

	this->top     = top;
	this->bottom  = bottom;
	this->eTop    = eTop;
	this->eBottom = eBottom;
}

Elevator *Elevator::calculate()
{

	return this;
}

void Elevator::init()
{
	top = bottom = NULL;
	eTop = eBottom = NULL;

	ball1 = ball2 = ball3 = NULL;
}
