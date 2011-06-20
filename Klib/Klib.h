using namespace std;
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

enum motorControlerType
{
	undefined,
	jaguar, ///< Jaguar motor controler
	victor, ///< Victor motor controler
};
enum airControlerType
{
	spike,
	solenoidBreakout,
};

#include "Wheels.cpp"
#include "chassis.cpp"
