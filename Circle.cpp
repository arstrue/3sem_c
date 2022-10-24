#include <iostream>
#include <cmath>
#include "point.h"
#include "Circle.h"
using std::cout;
using std::endl;

	Point Circle::getCenter()
	{
		return mCenter;
	}

	float Circle::getRadius()
	{
		return mRadius;
	}

	void Circle::setCenter(Point p)
	{
		mCenter = p;
	}

	void Circle::setRadius(float r)
	{
		mRadius = 0;
		if (r > 0)
			mRadius = r;
	}

	Circle::Circle()
	{
		mCenter = Point(0, 0);
		mRadius = 1;
	};

	Circle::Circle(Point p, float r)
	{
		mCenter = p;
		mRadius = r;
	}

	Circle::Circle(const Circle& c)
	{
		mRadius = c.mRadius;
		mCenter = c.mCenter;
	}

	float Circle::getArea() const
	{
		return acos(-1) * mRadius * mRadius;//pi*r^2
	}

	float Circle::getDistance(const Point& p) const
	{
		float dist = p.distance(mCenter);
		return abs(dist - mRadius);
	}

	bool Circle::isColliding(const Circle& c) const
	{
		if (mRadius + c.mRadius >= mCenter.distance(c.mCenter))
			return true;
		return false;
	}

	void Circle::move(const Point& p)//здесь понимаем р как радиус-вектор
	{
		mCenter.setX(mCenter.getX() + p.getX());
		mCenter.setX(mCenter.getX() + p.getX());
	}
