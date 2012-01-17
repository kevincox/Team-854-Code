#ifndef BALL_H
#define BALL_H

class Ball
{
	double pos;

	static double radius;
	static double diameter;

	void init (void);

public:
	Ball() {}

	Ball *setPos(double pos);

	double getBegining();
	double getCenter(void);
	double getEnd(void);
};

#endif // BALL_H
