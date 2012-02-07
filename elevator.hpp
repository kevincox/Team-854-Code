#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <WPILib.h>
#include <SpeedController.h>
#include <Encoder.h>

#include "ball.hpp"
#include <DigitalInput.h>

class Elevator
{
public:
	typedef UINT8 ElevatorPosition;
	
	const static ElevatorPosition drivePos = 1;
	const static ElevatorPosition shootPos = 2;

private:
	ElevatorPosition pos;

	Ball *ball1, *ball2, *ball3;

	SpeedController *top, *bottom;
	Encoder *eTop, *eBottom;
	DigitalInput *iTop, *iIn, *iEnter;

	double speed;

	int ballsToShoot;

	void init(void);
	void newBall(void);
	void rotateBall(void);

public:
	Elevator(SpeedController *top, SpeedController *bottom,
	          Encoder *eTop, Encoder *eBottom,
	          DigitalInput *iTop, DigitalInput *iIn,
	          DigitalInput *iEnter
	        );

	Elevator *update(void);

	Elevator* shoot();
	Elevator* shootPosition();
	Elevator* pickUpPosition();
	Elevator* stopMoving();
	bool pickUpBall();

	void testSensor ();
	
	bool isFull(void);

	ElevatorPosition getPosition(void);
	Elevator *setPosition(ElevatorPosition pos);

};

#endif // ELEVATOR_HPP
