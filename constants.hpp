
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

namespace Constants
{
	extern const UINT32 motorLSlot;
	extern const UINT32 motorLChannel;
	extern const UINT32 motorRSlot;
	extern const UINT32 motorRChannel;
	extern const UINT32 bottomElevatorMotorSlot;
	extern const UINT32 bottomElevatorMotorChannel;
	extern const UINT32 topElevatorMotorSlot;
	extern const UINT32 topElevatorMotorChannel;
	extern const UINT32 brushMotorSlot;
	extern const UINT32 brushMotorChannel;

	extern const double motorLCorrection;
	extern const double motorRCorrection;
	extern const double bottomElevatorMotorCorrection;
	extern const double topElevatorMotorCorrection;

	extern const UINT32 accel1Slot;
	extern const UINT32 accel1Channel;

	extern const UINT32 jsDrivePort;

	extern const double jsDriveMaxX;
	extern const double jsDriveMaxY;

	extern const UINT32 sensorElevatorTopSlot;
	extern const UINT32 sensorElevatorTopChannel;
	extern const UINT32 sensorElevatorInSlot;
	extern const UINT32 sensorElevatorInChannel;
	extern const UINT32 sensorElevatorEnterSlot;
	extern const UINT32 sensorElevatorEnterChannel;


	extern const UINT32 jsDriveButtonReverse;
	extern const UINT32 jsDriveButtonShoot;
	extern const UINT32 jsDriveButtonShootPos;
	extern const UINT32 jsDriveButtonDrivePos;
	extern const UINT32 jsDriveButtonSweeperForwards;
	extern const UINT32 jsDriveButtonSweeperBackwards;

	extern const double jsDriveDeadbandXMax;
	extern  double jsDriveDeadbandXMin;
	extern const double jsDriveDeadbandYMax;
	extern const double jsDriveDeadbandYMin;

	extern const double ballDiameter;
	extern const double elevatorBallSpeed;

	extern const double PickerUpperForwardsSpeed;
	extern const double PickerUpperBackwardsSpeed;
	
	extern const double ballPassingBySensorTime;
}

#endif
