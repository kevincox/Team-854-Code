#include <iostream>
using namespace std;

#include "Robot2012.hpp"

Robot2012::Robot2012(void)
{
}

void Robot2012::RobotInit ()
{
	cerr << "Initilizing" << endl;

	cerr << "Loading Sensors" << endl;
	sensors = new Sensor();

	cerr << "Loading Human Inputs" << endl;
	inputs = new Input();

	cerr << "Loading Motor Controllers" << endl;
	ml = new Jaguar(constants.motorLSlot, constants.motorLChannel);
	mr = new Jaguar(constants.motorRSlot, constants.motorRChannel);

	cerr << "Loading Drive System" << endl;
	drive = new Drive(ml, mr);

	cerr << "Loading Output" << endl;
	output = new DSOutput(this);

	cerr << "Initilized" <<
		"---------------------" << endl;
}

void Robot2012::TeleopPeriodic (void)
{
	output->update();
	//cerr << sensors->getAccelVal(1) << endl;
}

void Robot2012::TeleopContinuous (void)
{
	inputs->update();

	drive->setFlip(inputs->driveFlipped());

	drive->setVelocity(inputs->driveDirection());
	drive->calculate();

	drive->update();
}

START_ROBOT_CLASS(Robot2012);

