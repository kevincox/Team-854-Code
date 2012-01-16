
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

struct Constants
{
	UINT32 motorLSlot;
	UINT32 motorLChannel;
	UINT32 motorRSlot;
	UINT32 motorRChannel;
	UINT32 accel1Slot;
	UINT32 accel1Channel;
	UINT32 jsDrivePort;

	double jsDriveMaxX;
	double jsDriveMaxY;

	const UINT32 jsDriveButtonReverse;

	double jsDriveDeadbandXMax;
	double jsDriveDeadbandXMin;
	double jsDriveDeadbandYMax;
	double jsDriveDeadbandYMin;

	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		accel1Slot(1),
		accel1Channel(3),
		jsDrivePort(1),
		jsDriveMaxX(1),
		jsDriveMaxY(1),
		jsDriveButtonReverse(5),
		jsDriveDeadbandXMax(0.05),
		jsDriveDeadbandXMin(-0.05),
		jsDriveDeadbandYMax(0.05),
		jsDriveDeadbandYMin(-0.05)
	{

	}
};

extern Constants constants;

#endif
