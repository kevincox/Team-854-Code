#include <iostream>
using namespace std;

#include "WPILib.h"

#include "Drive.hpp"
#include "Constants.hpp"
#include "Input.hpp"
#include "Sensor.hpp"

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
	Sensor *sensors;
	
public:
	Robot2012(void)
	{
	}
	
	void RobotInit ()
	{	
		cerr << "Init" << endl;
		
		cerr << "Loading Joysticks" << endl;
		inputs = new Input();

		cerr << "Loading Motor Controllers" << endl;
		ml = new Jaguar(constants.motorLSlot, constants.motorLChannel);
		mr = new Jaguar(constants.motorRSlot, constants.motorRChannel);

		cerr << "Loading Drive System" << endl;
		drive = new Drive(ml, mr);
		sensors = new Sensor();
		cerr << "Inited\n" <<
			"---------------------" << endl;
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
		inputs->update();
		
		drive->setVelocity(inputs->driveDirection());
		
		drive->drive();
		//fprintf(stderr, "Acceleration: % .4lf\n", sensors->getAccelVal(1));
		
	}
};

START_ROBOT_CLASS(Robot2012);

