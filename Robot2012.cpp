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

	//cerr << "Loading Sensors" << endl;
	//sensors = new Sensor();

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
	
	/*
	cerr << "Loading Camera" << endl;
	cam = new Camera();
	pthread_t camera;
	pthread_create(&camera, NULL, &Camera::main, (void*)cam);
	*/
	cerr << "Initilized\n" <<
		"-------------------------" << endl;
}

void Robot2012::DisabledPeriodic (void)
{
	output->update();
	//cerr << "iIn Value: " << i.Get() << endl;
	//cerr <<  "This is the throttle value: " << inputs->getShooterSpeed() << endl;
	cam->enable();

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

void Robot2012::AutonomousInit(void)
{
	timer.Reset();
	timer.Start();
	
	if ( Constants::autonomousShootingSpeed > 0 )
		shooter->calculate(Constants::autonomousShootingSpeed);
	else shooter->calculate(0);
	
	shooter->update();
	brush->setSpeed(1);
	brush->update();
	
	if(Constants::autonomousShootingSpeed >= 0.0)
		elevator->setPosition(Elevator::shootPos);
	else
		elevator->setPosition(Elevator::drivePos);
}

void Robot2012::AutonomousPeriodic (void)
{	
	if ( timer.Get() > 1.0 && Constants::autonomousShootingSpeed >= 0.0)
	{
		elevator->setPosition(Elevator::shooting);
	}
	else if(timer.Get() > 1.0 && Constants::autonomousShootingSpeed < 0.0)
	{
		elevator->setPosition(Elevator::pooping);
	}
	elevator->calculate(0);
	elevator->update();
	shooter->update();
	brush->update();
}

void Robot2012::AutonomousContinuous(void)
{

}

void Robot2012::TeleopInit(void)
{
	if(Constants::autonomousShootingSpeed < 0.0)
		elevator->setBalls(0);
}

void Robot2012::TeleopPeriodic (void)
{
	output->update();
	//cerr << sensors->getAccelVal(1) << endl;
}

void Robot2012::TeleopContinuous (void)
{
	/*inputs->update();
	double s = inputs->driveDirection().y;
	cerr << "Setting to: " << s <<endl;
	eb->Set(s);
	
	b->Set(1);
	
	return;//*/
	
	inputs->update();

	elevator->setPosition(inputs->getPos());

	drive->setFlip(inputs->driveFlipped());
	drive->setVelocity(inputs->driveDirection());

	elevator->calculate(inputs->getNumOfBallsToAdd());
	drive->calculate();
	shooter->calculate(inputs->getShooterSpeed());
	
	//bool dir = inputs->getSweeperIsForwards() && !elevator->isFull();
	brush->setDirection(/*dir*/true);

	drive->update();
	elevator->update();
	brush->update();
	shooter->update();
}

START_ROBOT_CLASS(Robot2012);

