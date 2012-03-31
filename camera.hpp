#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <WPILib.h>
#include <Vision/ColorImage.h>
#include <Timer.h>
#include <pthread.h>

class Camera {
private:
	pthread_mutex_t mutex;
	ColorImage ci;
	bool take;
	
public:
	Camera(void);
	Camera* calculate(void);
	Camera* update(void);
	Camera *enable(void);
	static void *main(void*);
};


#endif
