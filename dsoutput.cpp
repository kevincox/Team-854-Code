#include "dsoutput.hpp"

DSOutput::DSOutput(Robot2012 *robot)
{
	this->robot = robot;

	init();
}

void DSOutput::init()
{
	drive = robot->drive;
	
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

	if      (robot->IsDisabled())        out->PrintfLine(l1, "Mode: Disabled.");
	else if (robot->IsAutonomous())      out->PrintfLine(l1, "Mode: Autonomous.");
	else if (robot->IsOperatorControl()) out->PrintfLine(l1, "Mode: Teleop.");
	else                                 out->PrintfLine(l1, "Mode: WTF?!? I have no clue.");


	out->PrintfLine(l2, "Drive %s reversed.", drive->isFlipped()?"IS":"NOT");
	out->PrintfLine(l3, "L: % .4lf   R: % .4lf",
	                 drive->getLeftSpeed(), drive->getRightSpeed());
	out->PrintfLine(l4, "Sweeper %s reversed.", robot->brush->isForward()?"IS":"NOT");
	switch (robot->elevator->getPosition())	
	{
		case Elevator::drivePos:
			out->PrintfLine(l5, "E position is drive.");
			break;
		case Elevator::shootPos:
			out->PrintfLine(l5, "E position is shoot.");
			break;
		case Elevator::shooting:
			out->PrintfLine(l5, "E position is shooting.");
			break;
		default:
			out->PrintfLine(l5, "uh oh");
			break;
	}
	out->PrintfLine(l6, "Number of Balls: %d.", robot->elevator->getNumOfBalls());

	out->UpdateLCD();
}
