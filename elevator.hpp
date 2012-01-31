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

	UINT32 iEnterOnBefore;
	
	void init(void);
	void newBall(void);
	Elevator *doShoot(void);

public:
	Elevator(SpeedController *top, SpeedController *bottom,
	          Encoder *eTop, Encoder *eBottom,
	          DigitalInput *iTop, DigitalInput *iIn,
	          DigitalInput *iEnter
	        );

	Elevator *calculate (void);
	Elevator *update(void);

	Elevator* shoot(int numBalls);
	Elevator* shootPosition();
	Elevator* pickUpPosition();
	Elevator* stopMoving();

	void testSensor ();
	
	bool isFull(void);

	ElevatorPosition getPosition(void);
	Elevator *setPosition(bool shootPos, bool drivePos);
	Elevator *calculateBalls();
	int getNumOfBalls(); 

};

#endif // ELEVATOR_HPP
