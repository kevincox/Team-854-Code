#include "input.hpp"
#include "constants.hpp"

Input::Input():
	jsDrive(Constants::jsDrivePort)
{
	driveIsFlipped = false;
	pos = Elevator::drivePos;
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
	                   jsDrive.GetX()/Constants::jsDriveMaxX,
	                   jsDrive.GetY()/Constants::jsDriveMaxY*(-1)
	                 );

	if ( driveDir.x < Constants::jsDriveDeadbandXMax &&
		 driveDir.x > Constants::jsDriveDeadbandXMin ) driveDir.x = 0;
	if ( driveDir.y < Constants::jsDriveDeadbandYMax &&
		 driveDir.y > Constants::jsDriveDeadbandYMin ) driveDir.y = 0;

	bool s;

	s = jsDrive.GetRawButton(Constants::jsDriveButtonReverse);
	if ( s && !bFlipState ) driveIsFlipped = !driveIsFlipped;
	bFlipState = s;

	s = jsDrive.GetRawButton(Constants::jsDriveButtonShoot);
	if (s)  pos = Elevator::shooting;

	s = jsDrive.GetRawButton(Constants::jsDriveButtonShootPos);
	if (s && !shootPosButtonPressedBefore) pos = Elevator::shootPos;
	shootPosButtonPressedBefore = s;

	s = jsDrive.GetRawButton(Constants::jsDriveButtonDrivePos);
	if (s && !drivePosButtonPressedBefore) pos = Elevator::drivePos;
	drivePosButtonPressedBefore = s;
	
	s = jsDrive.GetRawButton(Constants::jsDriveButtonSweeperForwards);
	if(s && !forwardsButtonPressedBefore)sweeperIsForwards = true;
	forwardsButtonPressedBefore = s;
	
	s = jsDrive.GetRawButton(Constants::jsDriveButtonSweeperBackwards);
	if(s && !backwardsButtonPressedBefore)sweeperIsForwards = false;
	backwardsButtonPressedBefore = s;
	
	if(jsDrive.GetRawButton(Constants::jsDriveButtonShoot) == 0 &&
			pos == Elevator::shooting )
	{
		pos = Elevator::drivePos;
	}
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
	int b =  numOfBallsToShoot;
	numOfBallsToShoot = 0;
	return b;
}

bool Input::getSweeperIsForwards()
{
	return sweeperIsForwards;
}

Elevator::ElevatorPosition Input::getPos()
{
	return pos;
}
