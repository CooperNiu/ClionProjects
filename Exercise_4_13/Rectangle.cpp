//
// Created by Cooper on 13/04/2017.
//

#include "Rectangle.h"
void Rectangle::initRectangle(float x, float y, float w, float h)
{
	initPoint(x, y);
	this->w=w;
	this->h=h;
}
float Rectangle::getH() const
{ return h;}
float Rectangle::getW() const
{ return w;}
