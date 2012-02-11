#include "shooter.hpp"
#include "constants.hpp"

Shooter::Shooter(SpeedController *topMotor, SpeedController *bottomMotor)
{
	this->topMotor = topMotor;
	this->bottomMotor = bottomMotor;
}

Shooter::~Shooter()
{
}

Shooter *Shooter::calculate()
{
	topMotorSpeed = Constants::shooterTopMotorSpeed;
	bottomMotorSpeed = Constants::shooterBottomMotorSpeed;
	return this;
}

Shooter *Shooter::update()
{
	topMotor->Set(topMotorSpeed);
	bottomMotor->Set(bottomMotorSpeed);
	return this;
}
