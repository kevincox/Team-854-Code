#ifndef INPUT_HPP
#define INPUT_HPP

#include "WPILib.h"
#include "vectorLib/vector.hpp"

class Input
{
private:
	Joystick jsDrive;

	Vector driveDir;

	bool bFlipState;
	bool shootButtonPressedBefore;
	bool shootPosButtonPressedBefore;
	bool drivePosButtonPressedBefore;
	bool forwardsButtonPressedBefore;
	bool backwardsButtonPressedBefore;
	bool driveIsFlipped;
	bool forwardsButtonPressed;
	bool backwardsButtonPressed;
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
	bool getForwardsButtonPressed();
	bool getBackwardsButtonPressed();
	bool getShootPos();
	bool getDrivePos();
};

#endif
