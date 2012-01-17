#ifndef DRIVERSTATION_HPP
#define DRIVERSTATION_HPP

#include <WPILib.h>
#include <DriverStationLCD.h>

class DSOutput;

#include "Robot2012.hpp"
#include "drive.hpp"

class DSOutput
{
	DriverStationLCD *out;

	Robot2012 *robot;
	Drive *drive;

	void init();
public:
	DSOutput(Robot2012 *robot);

	void update();
};

#endif
