#include "backgroundcamera.hpp"

BackgroundCamera::BackgroundCamera(void)
{
	pthread_create( &thread1, NULL, &Camera::main, (void *)&cam);
}

BackgroundCamera::~BackgroundCamera(void)
{
	
}
