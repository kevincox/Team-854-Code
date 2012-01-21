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

};

#endif // PICKERUPPER_H
