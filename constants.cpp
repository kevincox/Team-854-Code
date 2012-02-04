#include "constants.hpp"

namespace Constants
{
	const UINT32 motorLSlot = 1;
	const UINT32 motorLChannel = 1;
	const UINT32 motorRSlot = 2;
	const UINT32 motorRChannel = 1;
	const UINT32 bottomElevatorMotorSlot = 1;
	const UINT32 bottomElevatorMotorChannel = 3;
	const UINT32 topElevatorMotorSlot = 1;
	const UINT32 topElevatorMotorChannel = 4;
	const UINT32 brushMotorSlot = 1;
	const UINT32 brushMotorChannel = 5;

	const double motorLCorrection = -1;
	const double motorRCorrection = 1;
	const double bottomElevatorMotorCorrection = 1;
	const double topElevatorMotorCorrection = 1;

	const UINT32 accel1Slot = 1;
	const UINT32 accel1Channel = 3;

	const UINT32 jsDrivePort = 1;

	const double jsDriveMaxX = 1;
	const double jsDriveMaxY = 1;

	const UINT32 sensorElevatorTopSlot = 1;
	const UINT32 sensorElevatorTopChannel = 1;
	const UINT32 sensorElevatorInSlot = 1;
	const UINT32 sensorElevatorInChannel = 2;
	const UINT32 sensorElevatorEnterSlot = 1;
	const UINT32 sensorElevatorEnterChannel = 3;

	const UINT32 jsDriveButtonReverse = 5;
	const UINT32 jsDriveButtonShoot = 1;
	const UINT32 jsDriveButtonShootPos = 6;
	const UINT32 jsDriveButtonDrivePos = 7;
	const UINT32 jsDriveButtonSweeperForwards = 11;
	const UINT32 jsDriveButtonSweeperBackwards = 10;

	const double jsDriveDeadbandXMax = 0.05;
	extern double jsDriveDeadbandXMin = -0.05;
	const double jsDriveDeadbandYMax = 0.05;
	const double jsDriveDeadbandYMin = -0.05;

	const double ballDiameter = 9;
	const double elevatorBallSpeed = 0.25;

	const double PickerUpperForwardsSpeed = 1.0;
	const double PickerUpperBackwardsSpeed = -1.0;
}
