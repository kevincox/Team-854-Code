#ifndef ROBOT2012_HPP
#define ROBOT2012_HPP

#include <iostream>
using namespace std;

#include "WPILib.h"
#include <Victor.h>

class Robot2012;

#include "drive.hpp"
#include "constants.hpp"
#include "input.hpp"
#include "sensor.hpp"
#include "dsoutput.hpp"
#include "elevator.hpp"

class Robot2012 : public IterativeRobot
{
public:
	Drive *drive;
	SpeedController *ml, *mr;

	Input *inputs;
	Sensor *sensors;
	
	Elevator *elevator;
	DigitalInput *elevatorSensorTop;

	DSOutput *output;

	Robot2012(void);
	void RobotInit ();
	void DisabledPeriodic(void);
	void DisabledContinuous(void);
	void AutonomousPeriodic(void);
	void AutonomousContinuous(void);
	void TeleopPeriodic (void);
	void TeleopContinuous (void);
};

#endif
