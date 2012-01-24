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
	
	bool shootButton;
	
	shootButton = jsDrive.GetRawButton(constants.jsDriveButtonShoot);
	if (shootButton && !shootButtonPressedBefore) shoot++;
	shootButtonPressedBefore = shootButton;
	
	bool shootPosButton;
	
	shootPosButton = jsDrive.GetRawButton(constants.jsDriveButtonShootPos);
	if(shootPosButton && !shootPosButtonPressedBefore) shootPos++;
	
	shootPosButtonPressedBefore = shootPosButton;
	
	bool pickUpPosButton;
	
	pickUpPosButton = jsDrive.GetRawButton(constants.jsDriveButtonPickUpPos);
	if(pickUpPosButton && !pickUpPosButtonPressedBefore)pickUp++;
	pickUpPosButtonPressedBefore = pickUpPosButton;
}

/*int Input::ballsToShoot()
{
	
}*/

bool Input::driveFlipped()
{
	return driveIsFlipped;
}
