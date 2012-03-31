#include "camera.hpp"
#include "constants.hpp"

#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"

using namespace std;

Camera::Camera ( void ):
	ci(IMAQ_IMAGE_HSL)
{
	pthread_mutex_init(&mutex, NULL);
	take = true;
}

Camera* Camera::calculate(void)
{
	AxisCamera &cam = AxisCamera::GetInstance("10.8.54.11");
	if (!cam.IsFreshImage())
				return this;
			
	take = false;
			
	int i = cam.GetImage(&ci);
	if (i) cerr << "image worked" << endl;
	else cerr << "image didn't work" << endl;
			
	//ci.Write("/colorimage.jpg");
		
	BinaryImage *bi = ci.ThresholdHSL(200, 55,
	                                  0, 255,
	                                  0, 200);
	//BinaryImage *bi = ci.ThresholdHSL(Constants::hueMin, Constants::hueMax, 
	//										  Constants::satMin, Constants::satMax, 
	//									      Constants::lumMin, Constants::lumMax);
	//BinaryImage *biggerObjects = bi->RemoveSmallObjects(false, 2);
	vector <ParticleAnalysisReport> *particleAnalysisList = bi->GetOrderedParticleAnalysisReports();
	Rect biggestRectangle = particleAnalysisList->at(0).boundingRect;
	
	int x = biggestRectangle.left + biggestRectangle.width/2;
	int y = biggestRectangle.top + biggestRectangle.height/2;
	
	cerr << "T: (" << x << "," << y << ")" << endl;
	
	bi->Write("/image.bmp");
	//delete bi;
	//delete particleAnalysisList;
	return this;
}

Camera* Camera::update ()
{
	if ( take )
	{		
		AxisCamera &cam = AxisCamera::GetInstance("10.8.54.11");
		if (!cam.IsFreshImage())
					return this;
		
		take = false;
			
		int i = cam.GetImage(&ci);
		if (i) cerr << "image worked" << endl;
		else cerr << "image didn't work" << endl;
		
		//ci.Write("/colorimage.jpg");
	
		//BinaryImage *bi = ci.ThresholdHSL(0, 128,
		//                                  0, 128,
		//                                  0, 128);
		BinaryImage *bi = ci.ThresholdHSL(Constants::hueMin, Constants::hueMax, 
										  Constants::satMin, Constants::satMax, 
									      Constants::lumMin, Constants::lumMax);
		//bi->Write("/image.bmp");
		delete bi;
	}
	return this;
}

Camera *Camera::enable()
{
	if (!take) cerr << "Armed!" << endl;
	take = true;
	return this;
}

void *Camera::main(void *vcam)
{
	Camera *cam = (Camera *)vcam;
	
	sleep(5);
	
	while(1)
	{
		cam->calculate();
		pthread_mutex_lock(&cam->mutex);
		cam->update();
		pthread_mutex_unlock(&cam->mutex);
	}
	
	return NULL;
}
