#include "driverstation.hpp"

DSOutput::DSOutput(Drive *drive)
{
	this->drive = drive;
}

void DSOutput::init()
{
	out = DriverStationLCD::GetInstance();
}

void DSOutput::update()
{
	if      (robot->IsDisabled())        out->Printf(1, 1, "Mode: Disabled");
	else if (robot->IsAutonomous())      out->Printf(1, 1, "Mode: Autonomous");
	else if (robot->IsOperatorControl()) out->Printf(1, 1, "Mode: Teleop");

	out->Printf(2, 1, "Drive %s reversed.", drive->isFlipped()?"IS":"NOT");
	out->Printf(3, 1, "L: % .4lf   R: % .4lf",
	             drive->getLeftSpeed(), drive->getRightSpeed());

	out->UpdateLCD();
}
