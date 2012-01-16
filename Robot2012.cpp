#include <iostream>
using namespace std;

#include "WPILib.h"

#include "Drive.hpp"
#include "Constants.hpp"
#include "Input.hpp"
#include "Sensor.hpp"
#include "dsoutput.hpp"

class Robot2012 : public IterativeRobot
{
private:
	Drive *drive;
	SpeedController *ml, *mr;

	Input *inputs;
	Sensor *sensors;

	DSOutput *output;

public:
	Robot2012(void)
	{
	}

	void RobotInit ()
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
		output = new DSOutput(this, drive);

		cerr << "Initilized" <<
			"---------------------" << endl;
	}

	void TeleopPeriodic (void)
	{
		output->update();
		//cerr << sensors->getAccelVal(1) << endl;
	}

	void TeleopContinuous (void)
	{
		inputs->update();

		drive->setVelocity(inputs->driveDirection());
		drive->calculate();

		drive->update();
	}
};

START_ROBOT_CLASS(Robot2012);

