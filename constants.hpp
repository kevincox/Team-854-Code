
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

struct Constants
{
	const UINT32 motorLSlot;
	const UINT32 motorLChannel;
	const UINT32 motorRSlot;
	const UINT32 motorRChannel;

	const double motorLCorrection;
	const double motorRCorrection;
	
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

	const double jsDriveDeadbandXMax;
	const double jsDriveDeadbandXMin;
	const double jsDriveDeadbandYMax;
	const double jsDriveDeadbandYMin;

	const double ballDiameter;
	
	const double jsDriveButtonShoot;
	const double jsDriveButtonShootPos;
	const double jsDriveButtonPickUpPos;

	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		motorLCorrection(-1),
		motorRCorrection(1),
		
		accel1Slot(1),
		accel1Channel(3),
		
		jsDrivePort(1),		
		jsDriveMaxX(1),
		jsDriveMaxY(1),

		sensorElevatorTopSlot(1),
		sensorElevatorTopChannel(9),
		sensorElevatorInSlot(1),
		sensorElevatorInChannel(9), //same channel?
		sensorElevatorEnterSlot (1),
		sensorElevatorEnterChannel(9), //same channel?


		
		jsDriveButtonReverse(5),
		jsDriveDeadbandXMax(0.05),
		jsDriveDeadbandXMin(-0.05),
		jsDriveDeadbandYMax(0.05),
		jsDriveDeadbandYMin(-0.05),
		ballDiameter(9),
		
		jsDriveButtonShoot(1),
		jsDriveButtonShootPos(6),
		jsDriveButtonPickUpPos(7)
	{

	}
};

extern Constants constants;

#endif
