#ifndef ROBOT2012_HPP
#define ROBOT2012_HPP

#include <iostream>
using namespace std;

#include "WPILib.h"
#include <Victor.h>

class Robot2012;

#include "drive.hpp"
#include "input.hpp"
#include "sensor.hpp"
#include "dsoutput.hpp"
#include "elevator.hpp"
#include "pickerupper.hpp"

class Robot2012 : public IterativeRobot
{
public:
	Drive *drive;
	SpeedController *ml, *mr, *eb, *et, *b;

	Input *inputs;
	Sensor *sensors;
	
	Elevator *elevator;
	DigitalInput *elevatorSensorTop;
	DigitalInput *elevatorSensorIn;
	DigitalInput *elevatorSensorEnter;
	
	PickerUpper *brush;

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
