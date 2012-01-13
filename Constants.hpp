
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP


struct Constants
{
	UINT32 motorLSlot;
	UINT32 motorLChannel;
	UINT32 motorRSlot;
	UINT32 motorRChannel;
	float js1MaxX;
	float js1MaxY;
	
	Constants ( ):
		motorLSlot(1),
		motorLChannel(1),
		motorRSlot(1),
		motorRChannel(3),
		js1MaxX(1),
		js1MaxY(1)
	{
		
	}
}constants;

#endif