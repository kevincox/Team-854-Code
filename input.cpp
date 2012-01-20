#include "input.hpp"
#include "constants.hpp"

Input::Input():
	jsDrive(constants.jsDrivePort)
{
	driveIsFlipped = false;
}

Input::~Input()
{

}

Vector Input::driveDirection()
{
	//fprintf(stderr, "[jsDrive]x: % .4lf y: % .4lf\n", driveDir.x, driveDir.y);

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
	if ( s && !bFlipState ) driveIsFlipped = !driveIsFlipped;
	bFlipState = s;
}

bool Input::driveFlipped()
{
	return driveIsFlipped;
}

void Input::elevator () //goes in periodic or continuous checking? in continuous now.
{
	if (jsDriveButtonShootPos) Elevator->shootPos();
	if (jsDriveButtonPickUpPos) Elevator->pickUpPos();
	if (jsDriveButtonShoot) Elevator->shoot();
}
