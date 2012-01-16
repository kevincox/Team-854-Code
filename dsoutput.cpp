#include "dsoutput.hpp"

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
	if      (robot->IsDisabled())        out->PrintfLine(1, 1, "Mode: Disabled");
	else if (robot->IsAutonomous())      out->PrintfLine(1, 1, "Mode: Autonomous");
	else if (robot->IsOperatorControl()) out->PrintfLine(1, 1, "Mode: Teleop");

	out->PrintfLine(2, 1, "Drive %s reversed.", drive->isFlipped()?"IS":"NOT");
	out->PrintfLine(3, 1, "L: % .4lf   R: % .4lf",
	                 drive->getLeftSpeed(), drive->getRightSpeed());

	out->UpdateLCD();
}
