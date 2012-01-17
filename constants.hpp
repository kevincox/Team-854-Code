
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

	const UINT32 jsDriveButtonReverse;

	const double jsDriveDeadbandXMax;
	const double jsDriveDeadbandXMin;
	const double jsDriveDeadbandYMax;
	const double jsDriveDeadbandYMin;

	const double ballDiameter;

	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		motorLCorrection(1),
		motorRCorrection(-1),
		
		accel1Slot(1),
		accel1Channel(3),
		
		jsDrivePort(1),		
		jsDriveMaxX(1),
		jsDriveMaxY(1),
		
		jsDriveButtonReverse(5),
		jsDriveDeadbandXMax(0.05),
		jsDriveDeadbandXMin(-0.05),
		jsDriveDeadbandYMax(0.05),
		jsDriveDeadbandYMin(-0.05),
		ballDiameter(9)
	{

	}
};

extern Constants constants;

#endif
