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
public:
	Input();
	~Input();

	Vector driveDirection();
	void update();
	bool driveFlipped();
	void elevator();
};

#endif
