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
	               jsDrive.GetY()/constants.js1MaxY*(-1)
	             );
}

void Input::outputCoords()
{
	Vector v = getDirection();
	
	cerr << "X: " << v.x << endl;
	cerr << "Y: " << v.y << endl;
}
