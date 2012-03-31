#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <WPILib.h>
#include <SpeedController.h>
#include <Encoder.h>

#include "ball.hpp"
#include <DigitalInput.h>
#include <Timer.h>

class Elevator
{
public:
	typedef UINT8 ElevatorPosition;
	
	const static ElevatorPosition drivePos = 1;
	const static ElevatorPosition shootPos = 2;
	const static ElevatorPosition shooting = 3;
	const static ElevatorPosition pooping = 4;

private:
	ElevatorPosition pos;

	Ball *ball1, *ball2, *ball3;

	SpeedController *top, *bottom;
	Encoder *eTop, *eBottom;
	DigitalInput *iTop, *iIn, *iEnter;
	
	Timer tITop, tIIn, tIEnter;

	double speed;

	bool iEnterOnBefore;
	
	bool limboBall;
	
	void init(void);
	void newBall(void);
	Elevator *doShoot(void);

public:
	Elevator(SpeedController *top, SpeedController *bottom,
	          Encoder *eTop, Encoder *eBottom,
	          DigitalInput *iTop, DigitalInput *iIn,
	          DigitalInput *iEnter, int numOfBalls
	        );

	Elevator *calculate (int ballAdjustment);
	Elevator *update(void);

	Elevator* shootPosition();
	Elevator* pickUpPosition();
	Elevator* stopMoving();
	
	bool pickUpBall();
	Elevator* moveBallUp();
	
	bool isFull(void);

	ElevatorPosition getPosition(void);
	Elevator *setPosition(ElevatorPosition pos);
	bool calculateBalls(int ballAdjustment);
	int getNumOfBalls();
	Elevator* setSpeed(int newSpeed);
	Elevator* setBalls(int newBalls);
};

#endif // ELEVATOR_HPP
