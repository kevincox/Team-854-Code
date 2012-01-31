#include "input.hpp"
#include "constants.hpp"

Input::Input():
	jsDrive(constants.jsDrivePort)
{
	driveIsFlipped = false;
	shootPos = false;
	drivePos = false;
	numOfBallsToShoot = 0;
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
	if (shootButton && !shootButtonPressedBefore) numOfBallsToShoot++;
	shootButtonPressedBefore = shootButton;

	bool shootPosButton;

	shootPosButton = jsDrive.GetRawButton(constants.jsDriveButtonShootPos);
	if(shootPosButton && !shootPosButtonPressedBefore) shootPos = true;
	
	shootPosButtonPressedBefore = shootPosButton;

	bool drivePosButton;

	drivePosButton = jsDrive.GetRawButton(constants.jsDriveButtonDrivePos);
	if(drivePosButton && !drivePosButtonPressedBefore)drivePos = true;
	drivePosButtonPressedBefore = drivePosButton;
	
	bool forwardsButton;
	forwardsButton = jsDrive.GetRawButton(constants.jsDriveButtonSweeperForwards);
	if(forwardsButton && !forwardsButtonPressedBefore)forwardsButtonPressed = true;
	forwardsButtonPressedBefore = forwardsButton;
	
	bool backwardsButton;
	backwardsButton = jsDrive.GetRawButton(constants.jsDriveButtonSweeperBackwards);
	if(backwardsButton && !backwardsButtonPressedBefore)backwardsButtonPressed = true;
	backwardsButtonPressedBefore = backwardsButton;
}

/*int Input::ballsToShoot()
{

}*/

bool Input::driveFlipped()
{
	return driveIsFlipped;
}

int Input::getNumOfBallsToShoot ()
{
	return numOfBallsToShoot;
}

bool Input::getForwardsButtonPressed()
{
	if (forwardsButtonPressed)
	{
		forwardsButtonPressed = false;
		return true;
	}
	else return false;
}

bool Input::getBackwardsButtonPressed()
{
	if (backwardsButtonPressed)
	{
		backwardsButtonPressed = false;
		return true;
	}
	else return false;
}

bool Input::getShootPos()
{
	if(shootPos)
	{
		shootPos = false;
		return true;
	}
	else return false;
}

bool Input::getDrivePos()
{
	if(drivePos)
	{
		drivePos = false;
		return true;
	}
	else return false;
}
