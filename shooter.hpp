#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include <WPILib.h>
#include <SpeedController.h>


class Shooter
{
private:
	SpeedController *topMotor, *bottomMotor;
	double topMotorSpeed;
	double bottomMotorSpeed;
	
public:
	Shooter(SpeedController *topMotor, SpeedController *bottomMotor);
	~Shooter();
	
	Shooter *calculate();
	Shooter *update();
	
};

#endif // ELEVATOR_HPP
