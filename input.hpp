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
	bool driveIsFlipped;
	
	int shoot;
public:
	Input();
	~Input();

	Vector driveDirection();
	void update();
	int getShoot();
	bool driveFlipped();
	
};

#endif
