#include <iostream>
using namespace std;

#define TEST_BOARD

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

#ifdef TEST_BOARD
	#define SpeedControllerType Jaguar
#else
	#define SpeedControllerType Victor
#endif
	ml = new SpeedControllerType(Constants::motorLSlot,         Constants::motorLChannel);
	mr = new SpeedControllerType(Constants::motorRSlot,         Constants::motorRChannel);
	eb = new SpeedControllerType(Constants::motorElevatorBSlot, Constants::motorElevatorBChannel);
	et = new SpeedControllerType(Constants::motorElevatorTSlot, Constants::motorElevatorTChannel);
	 b = new SpeedControllerType(Constants::motorBrushSlot,     Constants::motorBrushChannel);

	cerr << "Loading Drive System" << endl;
	drive = new Drive(ml, mr);

	cerr << "Loading Output" << endl;
	output = new DSOutput(this);

	cerr << "Loading Elevator" << endl;
	elevatorSensorTop = new DigitalInput(Constants::sensorElevatorTopSlot,
	                                     Constants::sensorElevatorTopChannel);
	elevatorSensorIn = new DigitalInput(Constants::sensorElevatorInSlot,
	                                    Constants::sensorElevatorInChannel);
	elevatorSensorEnter = new DigitalInput(Constants::sensorElevatorEnterSlot,
	                                       Constants::sensorElevatorEnterChannel);
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

	/*
	for(int x = 1; x < 13; x++)
	{
		DigitalInput *sensor = new DigitalInput(1, x);
		cerr << x <<":"<< sensor->Get() << " ";
		delete sensor;
	}
	cerr << endl;
	//*/
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
	//cerr << sensors->getAccelVal(1) << endl;
}

void Robot2012::TeleopContinuous (void)
{
	inputs->update();

	elevator->setPosition(inputs->getPos());

	brush->reverseDirection(inputs->getSweeperIsForwards());

	drive->setFlip(inputs->driveFlipped());
	drive->setVelocity(inputs->driveDirection());

	elevator->calculate();
	drive->calculate();

	drive->update();
	elevator->update();
	brush->update();
}

START_ROBOT_CLASS(Robot2012);

