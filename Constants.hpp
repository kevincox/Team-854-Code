
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
	float js1MaxX;
	float js1MaxY;
	
	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(2),
		accel1Slot(1),
		accel1Channel(3),
		jsDrivePort(1),
		js1MaxX(1),
		js1MaxY(1)
	{
		
	}
};

extern Constants constants;

#endif
