
#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <WPILib.h>
#include "Constants.hpp"

class Sensor
{
private:
	//Gyro gyros[0];
	Accelerometer *accels[1];
	
public:
	Sensor();
	~Sensor();
	void init();
	double getAccelVal(int accelNum);
};

#ifdef HEADER_ONLY
	#include "Sensor.cpp"
#endif
#endif
