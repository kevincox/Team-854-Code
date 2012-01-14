#ifndef INPUT_HPP
#define INPUT_HPP

#include "WPILib.h"
#include "vectorLib/vector.hpp"

class Input
{
private:
	Joystick jsDrive;
	float x;
	float y;
	bool button2Pressed;
	bool button3Pressed;
public:
	Input();
	~Input();
	Vector getDirection();
	void outputCoords();
	void update();
};

#endif
