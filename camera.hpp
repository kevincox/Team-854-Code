#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <WPILib.h>
#include <Vision/ColorImage.h>
#include <Timer.h>

class Camera {
	ColorImage ci;
	bool take;
	
public:
	Camera(void);
	Camera* update();
	Camera *enable();
};


#endif
