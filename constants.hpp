
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

namespace Constants
{
	extern const UINT32 motorLSlot;
	extern const UINT32 motorLChannel;
	extern const UINT32 motorRSlot;
	extern const UINT32 motorRChannel;
	extern const UINT32 motorElevatorBSlot;
	extern const UINT32 motorElevatorBChannel;
	extern const UINT32 motorElevatorTSlot;
	extern const UINT32 motorElevatorTChannel;
	extern const UINT32 motorBrushSlot;
	extern const UINT32 motorBrushChannel;
	extern const UINT32 motorShooterBSlot;
	extern const UINT32 motorShooterBChannel;
	extern const UINT32 motorShooterTSlot;
	extern const UINT32 motorShooterTChannel;

	extern const double motorLCorrection;
	extern const double motorRCorrection;
	extern const double bottomElevatorMotorCorrection;
	extern const double topElevatorMotorCorrection;
	extern const double motorBrushCorrection;

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
	extern const UINT32 startingBallsButton1Slot;
	extern const UINT32 startingBallsButton1Channel;
	extern const UINT32 startingBallsButton2Slot;
	extern const UINT32 startingBallsButton2Channel;

	extern const UINT32 jsDriveButtonReverse;
	extern const UINT32 jsDriveButtonShoot;
	extern const UINT32 jsDriveButtonShootPos;
	extern const UINT32 jsDriveButtonDrivePos;
	extern const UINT32 jsDriveButtonDeleteBall;
	extern const UINT32 jsDriveButtonAddBall;
	extern const UINT32 jsDriveButtonSweeperForwards;
	extern const UINT32 jsDriveButtonSweeperBackwards;

	extern const double jsDriveDeadbandXMax;
	extern const double jsDriveDeadbandXMin;
	extern const double jsDriveDeadbandYMax;
	extern const double jsDriveDeadbandYMin;

	extern const double ballDiameter;
	extern const double elevatorBallSpeed;
	extern const double elevatorBallSpeediEnter;
	extern const double elevatorBallSpeediIn;

	extern const double PickerUpperForwardsSpeed;
	extern const double PickerUpperBackwardsSpeed;
	
	extern const double shooterTopMotorModifier;
	extern const double shooterBottomMotorModifier;
	
	extern const int hueMin;
	extern const int hueMax;
	extern const int satMin;
	extern const int satMax;
	extern const int lumMin;
	extern const int lumMax;
	
	extern const bool autonomousShootingMode;
	extern const double autonomousShootingSpeed;
}

#endif
