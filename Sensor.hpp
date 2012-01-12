
#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "WPILib.h"

class Sensor
{
private:
	vector <Gyro> gyros;
	vector <Accelerometer> accels;
	
public:
	Sensor();
	~Sensor();
	
};

#ifdef HEADER_ONLY
	#include "Sensor.cpp"
#endif
#endif
