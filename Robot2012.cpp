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
	b  = new SpeedControllerType(Constants::motorBrushSlot,     Constants::motorBrushChannel);
	sb = new SpeedControllerType(Constants::motorShooterBSlot,  Constants::motorShooterBChannel);
	st = new SpeedControllerType(Constants::motorShooterTSlot,  Constants::motorShooterTChannel);


	cerr << "Loading Drive System" << endl;
	drive = new Drive(ml, mr);

	cerr << "Loading Output" << endl;
	output = new DSOutput(this);

	cerr << "Loading Elevator" << endl;
	startingButton1 = new DigitalInput(Constants::startingBallsButton1Slot,
										Constants::startingBallsButton1Channel);
	startingButton2 = new DigitalInput(Constants::startingBallsButton2Slot,
			                            Constants::startingBallsButton2Channel);
	
	int numOfBalls = startingButton1->Get();
	numOfBalls += startingButton2->Get() << 1;
	
	elevatorSensorTop   = new DigitalInput(Constants::sensorElevatorTopSlot,
	                                       Constants::sensorElevatorTopChannel);
	elevatorSensorIn    = new DigitalInput(Constants::sensorElevatorInSlot,
	                                       Constants::sensorElevatorInChannel);
	elevatorSensorEnter = new DigitalInput(Constants::sensorElevatorEnterSlot,
	                                       Constants::sensorElevatorEnterChannel);
	elevator = new Elevator(et, eb,
							NULL, NULL,
							elevatorSensorTop, elevatorSensorIn, elevatorSensorEnter,
							numOfBalls);
	cerr << "Loading Picker Upper" << endl;
	
	brush = new PickerUpper(b);
	
	cerr << "Loading Shooter" << endl;
	shooter = new Shooter(sb, st);
	
	cerr << "Loading Camera" << endl;
	//cam = new Camera();
	
	cerr << "Initilized\n" <<
		"-------------------------" << endl;
}

void Robot2012::DisabledPeriodic (void)
{
	output->update();
	//cam->enable();

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
	//cam->update();
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

	drive->setFlip(inputs->driveFlipped());
	drive->setVelocity(inputs->driveDirection());

	elevator->calculate();
	drive->calculate();
	
	bool dir = inputs->getSweeperIsForwards() && !elevator->isFull();
	brush->setDirection(dir);

	drive->update();
	elevator->update();
	brush->update();
}

START_ROBOT_CLASS(Robot2012);

