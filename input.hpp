#ifndef INPUT_HPP
#define INPUT_HPP

#include "WPILib.h"
#include "vectorLib/vector.hpp"
#include "Elevator.hpp"

class Input
{
private:
public:Joystick jsDrive;
private:

	Vector driveDir;
	
	bool shooting;
	Elevator::ElevatorPosition pos;

	bool bFlipState;
	bool shootButtonPressedBefore;
	bool shootPosButtonPressedBefore;
	bool drivePosButtonPressedBefore;
	bool forwardsButtonPressedBefore;
	bool backwardsButtonPressedBefore;
	bool addBallButtonPressedBefore;
	bool deleteBallButtonPressedBefore;
	bool driveIsFlipped;
	bool sweeperIsForwards;

	int numOfBallsToAdd;
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
	float getShooterSpeed( void );
	int getNumOfBallsToAdd( void );

};

#endif
