#include <iostream>
#include "circle.hpp"
#include <math.h>
#include <cmath>

Circle::Circle(Vec2 const& c, float r):
center_{c},
radius_{r},
color_{{0.0}}
{}

Circle::Circle(Vec2 const& c, float r, Color const& col):
center_{c},
radius_{r},
color_{col}
{}

Vec2 Circle::getCenter() const {
	return center_;
}

float Circle::getRadius() const {
	return radius_;
}

bool operator<( Circle const& c1 , Circle const& c2 ) {
	if(c1.getRadius()<c2.getRadius()) {
		return true;
	}
	else return false;
}
bool operator>( Circle const& c1 , Circle const& c2 ) {
	if(c1.getRadius()>c2.getRadius()) {
		return true;
	}
	else return false;
}
bool operator==( Circle const& c1 , Circle const& c2 ) {
	if (c1.getRadius()==c2.getRadius())
	{
		return true;
	}
	else return false;
}
