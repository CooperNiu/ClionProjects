//
// Created by Cooper on 13/04/2017.
//
#ifndef EXERCISE_4_13_POINT_H
#define EXERCISE_4_13_POINT_H
class Point
{
public:
	void initPoint(float x = 0, float y = 0);
	void move(float offX, float offY);
	float getX() const;
	float getY() const;
private:
	float x, y;
};
#endif //EXERCISE_4_13_POINT_H
