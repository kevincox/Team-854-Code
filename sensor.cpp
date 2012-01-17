#include "sensor.hpp"
#include "constants.hpp"

Sensor::Sensor()
{
	init();
}

Sensor::~Sensor()
{

}

void Sensor::init()
{
	accels[0] = new Accelerometer(constants.accel1Slot, constants.accel1Channel);

}

double Sensor::getAccelVal(int accelNum)
{
	return (double)accels[accelNum - 1]->GetAcceleration();
}
