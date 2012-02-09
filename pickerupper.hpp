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
	PickerUpper * reverseDirection(bool forwards);
	PickerUpper * update();
	void setSpeed(double speed);
	double getSpeed();
	PickerUpper *goForwards();
	PickerUpper *goBackwards();
	bool isForward();

};

#endif // PICKERUPPER_H
