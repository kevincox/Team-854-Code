#include <iostream>
using namespace std;

#include "WPILib.h"

#include "Drive.hpp"
#include "Constants.hpp"
#include "Input.hpp"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class Robot2012 : public IterativeRobot
{
private:
	Drive *drive;
	SpeedController *ml, *mr;
	Input *inputs;
public:
	Robot2012(void)
	{
	}
	
	void RobotInit ()
	{	
		cerr << "INIT" << endl;
		
		cerr << "Loading Joysticks" << endl;
		inputs = new Input();
		
		ml = new Jaguar(constants.motorLSlot, constants.motorLChannel);
		mr = new Jaguar(constants.motorRSlot, constants.motorRChannel);
		drive = new Drive(ml, mr);
	}
	
	void Disabled ()
	{
		cerr << "DISABLED" << endl;
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void TeleopPeriodic (void)
	{
		drive->setVelocity(inputs->getDirection());
		drive->drive();
	}
};

START_ROBOT_CLASS(Robot2012);

