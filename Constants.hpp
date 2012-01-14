
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <WPILib.h>

struct Constants
{
	const UINT32 motorLSlot;
	const UINT32 motorLChannel;
	const UINT32 motorRSlot;
	const UINT32 motorRChannel;
	const UINT32 jsDrivePort;

	const double jsDriveMaxX;
	const double jsDriveMaxY;

	const double jsDriveButtonReverse;

	const double jsDriveDeadbandXMax;
	const double jsDriveDeadbandXMin;
	const double jsDriveDeadbandYMax;
	const double jsDriveDeadbandYMin;

	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		jsDrivePort(1),
		jsDriveMaxX(1),
		jsDriveMaxY(1),
		jsDriveButtonReverse(5),
		jsDriveDeadbandXMax(0.05),
		jsDriveDeadbandXMin(0.05),
		jsDriveDeadbandYMax(0.05),
		jsDriveDeadbandYMin(0.05)
	{

	}
};

extern Constants constants;

#endif
