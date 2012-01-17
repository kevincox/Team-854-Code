#include "ball.hpp"
#include "constants.hpp"

Ball::Ball()
{
	init();
}

Ball::Ball(double pos)
{
	init();
	setPos(pos);
}

void Ball::init(void)
{
	pos = 0;
	diameter = constants.ballDiameter;
	radius = constants.ballDiameter/2;
}

Ball *Ball::setPos(double pos)
{
	this->pos = pos;

	return this;
}

double Ball::getBegining(void)
{
	return pos - radius;
}

double Ball::getCenter(void)
{
	return pos;
}

double Ball::getEnd(void)
{
	return pos + radius;
}
