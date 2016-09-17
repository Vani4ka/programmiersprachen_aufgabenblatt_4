#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Circle
{
public:
	Circle(Vec2 const& c, float r);
	Circle(Vec2 const& c, float r, Color const& col);

	Vec2 getCenter() const;
	float getRadius() const;

private:
	Vec2 center_;
	float radius_;
	Color color_;
	
};

bool operator<( Circle const& c1 , Circle const& c2 );
bool operator>( Circle const& c1 , Circle const& c2 );
bool operator==( Circle const& c1 , Circle const& c2 );

#endif
