#ifndef PICKERUPPER_H
#define PICKERUPPER_H


class PickerUpper
{
private:
	SpeedController *motor;
	double speed;

public:

	PickerUpper(SpeedController *motor);
	~PickerUpper();

	void spin();
	void reverseDirection();
	void update();
	void setSpeed(int speed);
	double getSpeed();

};

#endif // PICKERUPPER_H
