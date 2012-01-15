#ifndef DRIVERSTATION_HPP
#define DRIVERSTATION_HPP

#include <WPILib.h>
#include <DriverStationLCD.h>

#include "Drive.hpp"

class DSOutput
{
	DriverStationLCD *out;

	IterativeRobot *robot;
	Drive *drive;

	void init();
public:
	DSOutput(IterativeRobot *robot, Drive *drive);

	void update();
};

#endif
