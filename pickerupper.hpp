#ifndef PICKERUPPER_H
#define PICKERUPPER_H
#include <SpeedController.h>
#include "constants.hpp"


class PickerUpper
{
private:
	SpeedController *motor;
	double speed;

public:

	PickerUpper(SpeedController *motor);
	~PickerUpper();

	void spin();
	PickerUpper * reverseDirection();
	PickerUpper * update();
	void setSpeed(double speed);
	double getSpeed();
	PickerUpper *goForwards();
	PickerUpper *goBackwards();

};

#endif // PICKERUPPER_H
