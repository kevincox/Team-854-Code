#ifndef BALL_H
#define BALL_H

class Ball
{
	double pos;

	double radius;
	double diameter;

	void init (void);

public:
	Ball();
	Ball(double pos);

	Ball *setPos(double pos);

	double getBegining();
	double getCenter(void);
	double getEnd(void);
	
	double move(double distance);
};

#endif // BALL_H
