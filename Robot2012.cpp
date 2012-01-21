#include <iostream>
using namespace std;

#include "Robot2012.hpp"

Robot2012::Robot2012(void)
{
}

void Robot2012::RobotInit ()
{
	cerr << "Initilizing" << endl;

	cerr << "Loading Sensors" << endl;
	sensors = new Sensor();

	cerr << "Loading Human Inputs" << endl;
	inputs = new Input();

	cerr << "Loading Motor Controllers" << endl;
	ml = new Victor(constants.motorLSlot, constants.motorLChannel);
	mr = new Victor(constants.motorRSlot, constants.motorRChannel);

	cerr << "Loading Drive System" << endl;
	drive = new Drive(ml, mr);

	cerr << "Loading Output" << endl;
	output = new DSOutput(this);

	cerr << "Loading Elevator" << endl;
	elevatorSensorTop = new DigitalInput(constants.sensorElevatorTopSlot,
	                                      constants.sensorElevatorTopChannel);
	elevatorSensorIn = new DigitalInput(constants.sensorElevatorInSlot,
											constants.sensorElevatorInChannel);
	elevatorSensorEnter = new DigitalInput(constants.sensorElevatorEnterSlot,
												constants.sensorElevatorEnterChannel);
	elevator = new Elevator(NULL, NULL,
							NULL, NULL,
							elevatorSensorTop, elevatorSensorIn, elevatorSensorEnter);

	cerr << "Initilized\n" <<
		"-------------------------" << endl;
}

void Robot2012::DisabledPeriodic (void)
{
	output->update();
}

void Robot2012::DisabledContinuous(void)
{

}

void Robot2012::AutonomousPeriodic (void)
{
	output->update();
}

void Robot2012::AutonomousContinuous(void)
{

}

void Robot2012::TeleopPeriodic (void)
{
	output->update();
	elevator->testSensor();
	//cerr << sensors->getAccelVal(1) << endl;
}

void Robot2012::TeleopContinuous (void)
{
	inputs->update();

	elevator->update();
	brush->update();

	drive->setFlip(inputs->driveFlipped());

	drive->setVelocity(inputs->driveDirection());
	drive->calculate();

	drive->update();
	elevator->shoot(inputs->numOfBallsToShoot);
}

START_ROBOT_CLASS(Robot2012);

