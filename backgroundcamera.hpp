#ifndef BACKGROUNDCAMERA_HPP
#define BACKGROUNDCAMERA_HPP

#include <pthread.h>

#include "camera.hpp"

class BackgroundCamera
{
private:
	pthread_t thread1;
	Camera cam;
	
public:
	BackgroundCamera();
	~BackgroundCamera();
};

#endif // BACKGROUNDCAMERA_HPP
