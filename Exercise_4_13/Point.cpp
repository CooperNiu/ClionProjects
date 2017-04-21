//
// Created by Cooper on 13/04/2017.
//

#include "Point.h"

void Point::initPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}
void Point::move(float offX, float offY)
{
	x += offX;
	y += offY;
}
float Point::getX() const
{
	return x;
}
float Point::getY() const
{
	return y;
}
