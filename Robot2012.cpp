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
	eb = new Victor(constants.bottomElevatorMotorSlot, constants.bottomElevatorMotorChannel);
	et = new Victor(constants.topElevatorMotorSlot, constants.topElevatorMotorChannel);
	b = new Victor(constants.brushMotorSlot, constants.brushMotorChannel);

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
	elevator = new Elevator(et, eb,
							NULL, NULL,
							elevatorSensorTop, elevatorSensorIn, elevatorSensorEnter);
	cerr << "Loading Picker Upper" << endl;
	brush = new PickerUpper(b);
	
	cerr << "Initilized\n" <<
		"-------------------------" << endl;
}

void Robot2012::DisabledPeriodic (void)
{
	output->update();
	brush->setSpeed(0);
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
	
	elevator->shoot(inputs->getNumOfBallsToShoot());

	brush->reverseDirection(inputs->getForwardsButtonPressed(), inputs->getBackwardsButtonPressed());

	drive->setFlip(inputs->driveFlipped());
	drive->setVelocity(inputs->driveDirection());
	
	elevator->calculate();
	drive->calculate();

	drive->update();
	elevator->update();
	brush->update();
}

START_ROBOT_CLASS(Robot2012);

