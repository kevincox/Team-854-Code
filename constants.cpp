#include "constants.hpp"

namespace Constants
{
	const UINT32 motorLSlot = 1;
	const UINT32 motorLChannel = 1;
	const UINT32 motorRSlot = 1;
	const UINT32 motorRChannel = 2;
	const UINT32 motorElevatorBSlot = 1;
	const UINT32 motorElevatorBChannel = 3;
	const UINT32 motorElevatorTSlot = 1;
	const UINT32 motorElevatorTChannel = 3;
	const UINT32 motorShooterBSlot = 1;
	const UINT32 motorShooterBChannel = 5;
	const UINT32 motorShooterTSlot = 1;
	const UINT32 motorShooterTChannel = 6;
	const UINT32 motorBrushSlot = 1;
	const UINT32 motorBrushChannel = 4;
	
	const double motorLCorrection = -1;
	const double motorRCorrection = 1;

	const double bottomElevatorMotorCorrection = 1;
	const double topElevatorMotorCorrection = 1;
	const double motorBrushCorrection = -1;

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
	const double jsDriveDeadbandXMin = -0.05;
	const double jsDriveDeadbandYMax = 0.05;
	const double jsDriveDeadbandYMin = -0.05;

	const double ballDiameter = 9;
	const double elevatorBallSpeed = 0.25;

	const double PickerUpperForwardsSpeed = 1.0;
	const double PickerUpperBackwardsSpeed = -1.0;
	
	const double shooterTopMotorSpeed = 1.0;
	const double shooterBottomMotorSpeed = 1.0;
}
