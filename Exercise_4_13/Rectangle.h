//
// Created by Cooper on 13/04/2017.
//

#ifndef EXERCISE_4_13_RECTANGLE_H
#define EXERCISE_4_13_RECTANGLE_H

#include <cmath>
#include "Point.h"
class Rectangle: public Point
// class Rectangle : private Point // 继承方式为private
// class Rectangle : protected Point  // 继承方式为protected
{
public:
	void initRectangle(float x, float y, float w, float h);
	float getH() const;
	float getW() const;
private:
	float w, h;
};


#endif //EXERCISE_4_13_RECTANGLE_H
