#include "Input.hpp"
#include "Constants.hpp"

Input::Input():
	jsDrive(constants.jsDrivePort)
{
}

Input::~Input()
{

}

Vector Input::driveDirection()
{
	//*
	cerr << "X: " << v.x << endl;
	cerr << "Y: " << v.y << endl;
	//*/
	return driveDir;
}

void Input::update()
{
	driveDir = Vector(Vector::xy,
	                   jsDrive.GetX()/constants.js1MaxX,
	                   jsDrive.GetY()/constants.js1MaxY*(-1)
	                 );

	if ( driveDir.x < constants.jsDriveDeadbandXMax &&
		 driveDir.x > constants.jsDriveDeadbandXMin ) driveDir.x = 0;
	if ( driveDir.y < constants.jsDriveDeadbandYMax &&
		 driveDir.y > constants.jsDriveDeadbandYMin ) driveDir.y = 0;

	bool s;

	s = jsDrive.GetButton();
	if ( s && !bFlipState ) bFlipPressed = true;
	bFlipState = s;
}

bool Input::filpPressed()
{
	var r = bFlipPressed;
	bFlipPressed = false;
	return r;
}
