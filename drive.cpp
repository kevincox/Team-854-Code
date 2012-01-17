#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#include "drive.hpp"

Drive::Drive(SpeedController *left, SpeedController *right):
	left(left),
	right(right)
{
	init();
}

void Drive::init()
{
	this->flipped = false;

	leftCorrection = rightCorrection = 1;
}

Drive::~Drive()
{

}

void Drive::calculate()
{
	leftSpeed = rightSpeed = velocity.y; // Foreward velocity.

	leftSpeed  += velocity.x; // Modify by the turn.
	rightSpeed -= velocity.x; //

	leftSpeed  *= leftCorrection;  // Apply the wheel correction factor.
	rightSpeed *= rightCorrection; //

	double scale = 1/max(max(fabs(leftSpeed), fabs(rightSpeed)), 1);

	leftSpeed  *= scale; // Scale to the `-1 < speed < 1` range.
	rightSpeed *= scale;

	if (flipped) // We are driving backwards.
	{
		leftSpeed  *= -1; // Apply reversal.
		rightSpeed *= -1; //
	}

	//fprintf(stderr, "l: % .4lf r: % .4lf\n", ls, rs);
}

void Drive::update()
{
	left->Set(leftSpeed);
	right->Set(rightSpeed);

	//fprintf(stderr, "[Drive]l: % .4lf r: % .4lf\n", ls, rs);
}

double Drive::getLeftSpeed()
{
	return leftSpeed;
}

double Drive::getRightSpeed()
{
	return rightSpeed;
}

Vector Drive::getVelocity()
{
	return velocity;
}

Drive *Drive::setVelocity(const Vector &velocity)
{
	this->velocity = velocity;

	return this;
}

Drive *Drive::setFlip(bool flip)
{
	this->flipped = flip;

	return this;
}

bool Drive::flip ( )
{
	return flipped = !flipped;
}

bool Drive::isFlipped()
{
	return flipped;
}
