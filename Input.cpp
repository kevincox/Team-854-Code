#include "Input.hpp"
#include "Constants.hpp"

Input::Input():
	jsDrive(constants.jsDrivePort)
{
}

Input::~Input()
{
	
}

Vector Input::getDirection()
{
	return Vector(Vector::xy,
	               jsDrive.GetX()/constants.js1MaxX,
	               jsDrive.GetY()/constants.js1MaxY
	             );
}

void Input::outputCoords()
{
	cerr << "X: " << jsDrive.GetX()/constants.js1MaxX << endl;
	cerr << "Y: " << jsDrive.GetY()/constants.js1MaxY * -1<< endl;
}
