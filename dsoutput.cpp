#include "dsoutput.hpp"

DSOutput::DSOutput(IterativeRobot *robot, Drive *drive)
{
	this->drive = drive;

	init();
}

void DSOutput::init()
{
	out = DriverStationLCD::GetInstance();
}

const DriverStationLCD::Line l1 = DriverStationLCD::kUser_Line1;
const DriverStationLCD::Line l2 = DriverStationLCD::kUser_Line2;
const DriverStationLCD::Line l3 = DriverStationLCD::kUser_Line3;
const DriverStationLCD::Line l4 = DriverStationLCD::kUser_Line4;
const DriverStationLCD::Line l5 = DriverStationLCD::kUser_Line5;
const DriverStationLCD::Line l6 = DriverStationLCD::kUser_Line6;

void DSOutput::update()
{
/*
	if      (robot->IsDisabled())        out->PrintfLine(l1, "Mode: Disabled");
	else if (robot->IsAutonomous())      out->PrintfLine(l1, "Mode: Autonomous");
	else if (robot->IsOperatorControl()) out->PrintfLine(l1, "Mode: Teleop");
*/

	out->PrintfLine(l2, "Drive %s reversed.", drive->isFlipped()?"IS":"NOT");
	out->PrintfLine(l3, "L: % .4lf   R: % .4lf",
	                 drive->getLeftSpeed(), drive->getRightSpeed());

	out->UpdateLCD();
}
