
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

struct Constants
{
	const UINT32 motorLSlot;
	const UINT32 motorLChannel;
	const UINT32 motorRSlot;
	const UINT32 motorRChannel;
	const UINT32 bottomElevatorMotorSlot;
	const UINT32 bottomElevatorMotorChannel;
	const UINT32 topElevatorMotorSlot;
	const UINT32 topElevatorMotorChannel;
	const UINT32 brushMotorSlot;
	const UINT32 brushMotorChannel;

	const double motorLCorrection;
	const double motorRCorrection;
	const double bottomElevatorMotorCorrection;
	const double topElevatorMotorCorrection;

	const UINT32 accel1Slot;
	const UINT32 accel1Channel;

	const UINT32 jsDrivePort;

	const double jsDriveMaxX;
	const double jsDriveMaxY;

	const UINT32 sensorElevatorTopSlot;
	const UINT32 sensorElevatorTopChannel;
	const UINT32 sensorElevatorInSlot;
	const UINT32 sensorElevatorInChannel;
	const UINT32 sensorElevatorEnterSlot;
	const UINT32 sensorElevatorEnterChannel;


	const UINT32 jsDriveButtonReverse;
	const UINT32 jsDriveButtonShoot;
	const UINT32 jsDriveButtonShootPos;
	const UINT32 jsDriveButtonPickUpPos;
	const UINT32 jsDriveButtonSweeperForwards;
	const UINT32 jsDriveButtonSweeperBackwards;

	const double jsDriveDeadbandXMax;
	const double jsDriveDeadbandXMin;
	const double jsDriveDeadbandYMax;
	const double jsDriveDeadbandYMin;

	const double ballDiameter;

	const double PickerUpperForwardsSpeed;
	const double PickerUpperBackwardsSpeed;

	Constants ():
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		bottomElevatorMotorSlot(1),
		bottomElevatorMotorChannel(3),//Change later
		topElevatorMotorSlot(1),
		topElevatorMotorChannel(4),//Change later
		brushMotorSlot(1),
		brushMotorChannel(5),
		motorLCorrection(-1),
		motorRCorrection(1),
		bottomElevatorMotorCorrection(1),
		topElevatorMotorCorrection(1),

		accel1Slot(1),
		accel1Channel(3),

		jsDrivePort(1),
		jsDriveMaxX(1),
		jsDriveMaxY(1),

		sensorElevatorTopSlot(1),
		sensorElevatorTopChannel(5),
		sensorElevatorInSlot(1),
		sensorElevatorInChannel(6),//plug sensor into this number + 2
		sensorElevatorEnterSlot (1),
		sensorElevatorEnterChannel(7),



		jsDriveButtonReverse(5),
		jsDriveButtonShoot(1),
		jsDriveButtonShootPos(6),
		jsDriveButtonPickUpPos(7),
		jsDriveButtonSweeperForwards(11),
		jsDriveButtonSweeperBackwards(10),
		jsDriveDeadbandXMax(0.05),
		jsDriveDeadbandXMin(-0.05),
		jsDriveDeadbandYMax(0.05),
		jsDriveDeadbandYMin(-0.05),
		ballDiameter(9),
		PickerUpperForwardsSpeed(1.0),
		PickerUpperBackwardsSpeed(-1.0)
	{

	}
};

extern Constants constants;

#endif
