#ifndef INPUT_HPP
#define INPUT_HPP

#include "WPILib.h"
#include "vectorLib/vector.hpp"

class Input
{
private:
	Joystick jsDrive;
public:
	Input();
	~Input();
	Vector getVector();
};

#endif
