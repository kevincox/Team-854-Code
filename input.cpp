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
	return driveDir;
}

void Input::update()
{
	driveDir = Vector(Vector::xy,
	                   jsDrive.GetX()/constants.jsDriveMaxX,
	                   jsDrive.GetY()/constants.jsDriveMaxY*(-1)
	                 );

	if ( driveDir.x < constants.jsDriveDeadbandXMax &&
		 driveDir.x > constants.jsDriveDeadbandXMin ) driveDir.x = 0;
	if ( driveDir.y < constants.jsDriveDeadbandYMax &&
		 driveDir.y > constants.jsDriveDeadbandYMin ) driveDir.y = 0;

	bool s;

	s = jsDrive.GetRawButton(constants.jsDriveButtonReverse);
	if ( s && !bFlipState ) bFlipPressed = true;
	bFlipState = s;
}

bool Input::filpPressed()
{
	bool r = bFlipPressed;
	bFlipPressed = false;
	return r;
}
