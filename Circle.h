#pragma once

#include <iostream>
#include <cmath>
#include "point.h"
using std::cout;
using std::endl;


class Circle
{
private:
	Point mCenter;
	float mRadius;
public:

	Point getCenter();
	float getRadius();
	void setCenter(Point p);
	void setRadius(float r);
	Circle();
	Circle(Point p, float r);
	Circle(const Circle& c);
	float getArea() const;
	float getDistance(const Point& p) const;
	bool isColliding(const Circle& c) const;
	void move(const Point& p);
};
