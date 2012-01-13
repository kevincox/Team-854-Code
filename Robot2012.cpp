#include "WPILib.h"

#include "Drive.hpp"
#include "Constants.hpp"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class Robot2012 : public SimpleRobot
{
private:
	Drive *drive;
	SpeedController *ml, *mr;
public:
	Robot2012(void)
	{
	}
	
	void init ()
	{	
		ml = new Jaguar(constants.motorLSlot, constants.motorLChannel);
		mr = new Jaguar(constants.motorRSlot, constants.motorRChannel);
		drive = new Drive(ml, mr);	
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
	void OperatorControl(void)
	{
	}
};

START_ROBOT_CLASS(Robot2012);

