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
	bool pickUpPosButtonPressedBefore;
	bool driveIsFlipped;
	
	int shoot;
	int shootPos;
	int pickUp;

public:
	Input();
	~Input();

	Vector driveDirection();
	void update();
	int getShoot();
	bool driveFlipped();
	
};

#endif
