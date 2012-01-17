#ifndef ROBOT2012_HPP
#define ROBOT2012_HPP

#include <iostream>
using namespace std;

#include "WPILib.h"

class Robot2012;

#include "drive.hpp"
#include "constants.hpp"
#include "input.hpp"
#include "sensor.hpp"
#include "dsoutput.hpp"

class Robot2012 : public IterativeRobot
{
public:
	Drive *drive;
	SpeedController *ml, *mr;

	Input *inputs;
	Sensor *sensors;

	DSOutput *output;

	Robot2012(void);
	void RobotInit ();
	void TeleopPeriodic (void);
	void TeleopContinuous (void);
};

#endif
