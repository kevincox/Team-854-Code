#include "camera.hpp"
#include "constants.hpp"

using namespace std;

Camera::Camera ( void ):
	ci(IMAQ_IMAGE_HSL)
{
	take = true;
}

Camera* Camera::update ()
{
	AxisCamera &cam = AxisCamera::GetInstance("10.8.54.11");
	if (!cam.IsFreshImage())
				return this;
	
	if ( take )
	{
		take = false;
		std::cerr << "Say cheese!" << std::endl;
		
		int i = cam.GetImage(&ci);
		if (i) cerr << "image worked" << endl;
		else cerr << "image didn't work" << endl;
	
		BinaryImage *bi = ci.ThresholdHSL(0, 180,
				                          0, 50,
				                          0, 50);
		//BinaryImage *bi = ci.ThresholdHSL(Constants::hueMin, Constants::hueMax, 
		//								  Constants::satMin, Constants::satMax, 
		//							      Constants::lumMin, Constants::lumMax);
		bi->Write("/image.jpg");
//		delete bi;
	}
	return this;
}

Camera *Camera::enable()
{
	take = true;
	return this;
}
