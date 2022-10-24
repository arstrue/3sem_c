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

	Point getCenter()
	{
		return mCenter;
	}

	float getRadius()
	{
		return mRadius;
	}

	void setCenter(Point p)
	{
		mCenter = p;
	}

	void setRadius(float r)
	{
		mRadius = 0;
		if(r > 0)
			mRadius = r;
	}
	
	Circle()
	{
		mCenter = Point(0,0);
		mRadius = 1;
	};

	Circle(Point p, float r)
	{
		mCenter = p;
		mRadius = r;
	}

	Circle(const Circle& c)
	{
		mRadius = c.mRadius;
		mCenter = c.mCenter;
	}

	float getArea() const
	{
		return acos(-1) * mRadius * mRadius;//pi*r^2
	}

	float getDistance(const Point& p) const
	{
		float dist = p.distance(mCenter);
		return abs(dist - mRadius);
	}

	bool isColliding(const Circle& c) const
	{
		if (mRadius + c.mRadius >= mCenter.distance(c.mCenter))
			return true;
		return false;
	}

	void move(const Point& p)//здесь понимаем р как радиус-вектор
	{
		mCenter.setX(mCenter.getX() + p.getX());
		mCenter.setX(mCenter.getX() + p.getX());
	}
};
