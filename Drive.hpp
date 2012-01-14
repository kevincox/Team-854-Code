
#ifndef DRIVE_HPP
#define DRIVE_HPP

#include "vectorLib/vector.hpp"

#include <SpeedController.h>

class Drive
{

private:
	bool flipped;

	Vector velocity;
	SpeedController *left;
	SpeedController *right;

	void init(void);

public:
	double leftCorrection;
	double rightCorrection;

	Drive(SpeedController *left, SpeedController *right);
	~Drive();
	void drive();
	Vector getVelocity();
	Drive *setVelocity(const Vector &velocity);
	Drive *setFlip(bool flip);
	bool flip(void);
	bool isFlipped();

};

#endif
