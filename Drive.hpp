
#ifndef DRIVE_HPP
#define DRIVE_HPP

#include "vectorLib/vector.hpp"

#include <WPILib.h>
#include <SpeedController.h>

class Drive
{
	bool flipped;

	double leftSpeed;
	double rightSpeed;

	Vector velocity;
	SpeedController *left;
	SpeedController *right;

	void init(void);

public:
	double leftCorrection;
	double rightCorrection;

	Drive(SpeedController *left, SpeedController *right);
	~Drive();

	void calculate();
	void update();

	double getLeftSpeed();
	double getRightSpeed();

	Vector getVelocity();
	Drive *setVelocity(const Vector &velocity);
	Drive *setFlip(bool flip);

	bool flip(void);
	bool isFlipped();

};

#endif
