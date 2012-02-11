#include "camera.hpp"
#include "constants.hpp"

Camera::Camera ( void )
{
	sleep(10);
	cam = &AxisCamera::GetInstance();
	ci = new ColorImage(IMAQ_IMAGE_HSL);
	take = true;
}

Camera* Camera::update ()
{
	if (!cam->IsFreshImage())
				return this;
	
	cam->GetImage(ci);
	/*BinaryImage *bi = ci->ThresholdHSL(Constants::hueMin, Constants::hueMax, 
										Constants::satMin, Constants::satMax, 
										Constants::lumMin, Constants::lumMax);*/
	if ( take )
	{
		take = false;
		//bi->Write("/image.jpg");
	}
	//free(bi);
	return this;
}

Camera *Camera::enable()
{
	take = true;
	return this;
}
