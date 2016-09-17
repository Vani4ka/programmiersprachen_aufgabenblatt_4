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

float Circle::circumference() const {
	return M_PI*radius_*2;
}


void Circle::draw(Window const& win) const {
	//Es geht einfach nicht.
}