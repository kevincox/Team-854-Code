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
	bool bFlipPressed;
public:
	Input();
	~Input();

	Vector driveDirection();
	void update();
	bool driveFlipped();
};

#endif
