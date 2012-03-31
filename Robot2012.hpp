#ifndef ROBOT2012_HPP
#define ROBOT2012_HPP

#include <iostream>
using namespace std;

#include "WPILib.h"
#include <Victor.h>
#include <Timer.h>

class Robot2012;

#include "drive.hpp"
#include "input.hpp"
#include "sensor.hpp"
#include "dsoutput.hpp"
#include "elevator.hpp"
#include "pickerupper.hpp"
#include "shooter.hpp"
#include "camera.hpp"
#include "backgroundcamera.hpp"

class Robot2012 : public IterativeRobot
{
private:
	Timer timer;
public:
	Drive *drive;
	SpeedController *ml, *mr, *eb, *et, *b, *sb, *st;

	Input *inputs;
	Sensor *sensors;
	
	Elevator *elevator;
	DigitalInput *elevatorSensorTop;
	DigitalInput *elevatorSensorIn;
	DigitalInput *elevatorSensorEnter;
	DigitalInput *startingButton1;
	DigitalInput *startingButton2;
	
	PickerUpper *brush;

	DSOutput *output;
	
	Shooter *shooter;
	
	Camera *cam;

	Robot2012(void);
	void RobotInit ();
	void DisabledPeriodic(void);
	void DisabledContinuous(void);
	void AutonomousInit(void);
	void AutonomousPeriodic(void);
	void AutonomousContinuous(void);
	void TeleopInit(void);
	void TeleopPeriodic (void);
	void TeleopContinuous (void);
};

#endif
