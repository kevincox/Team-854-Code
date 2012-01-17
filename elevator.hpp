#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <WPILib.h>
#include <SpeedController.h>
#include <Encoder.h>

#include "ball.hpp"
#include <DigitalInput.h>

class Elevator
{
	Ball *ball1, *ball2, *ball3;

	SpeedController *top, *bottom;
	Encoder *eTop, *eBottom;
	DigitalInput *iTop, *iIn, *iEnter;

	void init (void);

public:
	Elevator(SpeedController *top, SpeedController *bottom,
	          Encoder *eTop, Encoder *eBottom,
	          DigitalInput *iTop, DigitalInput *iIn,
	          DigitalInput *iEnter
	        );

	Elevator *calculate(void);
	Elevator *update(void);
	bool isFull(void);

};

#endif // ELEVATOR_HPP
