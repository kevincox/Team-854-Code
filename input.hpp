#ifndef INPUT_HPP
#define INPUT_HPP

#include "WPILib.h"
#include "vectorLib/vector.hpp"
#include "Elevator.hpp"

class Input
{
private:
	Joystick jsDrive;

	Vector driveDir;
	
	Elevator::ElevatorPosition pos;

	bool bFlipState;
	bool shootButtonPressedBefore;
	bool shootPosButtonPressedBefore;
	bool drivePosButtonPressedBefore;
	bool forwardsButtonPressedBefore;
	bool backwardsButtonPressedBefore;
	bool driveIsFlipped;
	bool sweeperIsForwards;
	bool shootPos;
	bool drivePos;

	int numOfBallsToShoot;

public:
	Input();
	~Input();

	Vector driveDirection();
	void update();
	int getShoot();
	bool driveFlipped();
	int getNumOfBallsToShoot();
	bool getSweeperIsForwards();
	Elevator::ElevatorPosition getPos();
};

#endif
