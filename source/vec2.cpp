#include <iostream>
#include "vec2.hpp"

Vec2::Vec2():
x(0.0f),
y(0.0f)
{}

Vec2::Vec2(float x_, float y_):
x(x_),
y(y_)
{}

float Vec2::getx() const {
	return x;
}

float Vec2::gety() const {
	return y;
}

Vec2& Vec2::operator+=( Vec2 const& v ){
	x += v.getx();
	y += v.gety();
	return *this;
}

Vec2& Vec2::operator-=( Vec2 const& v ) {
	x -= v.getx();
	y -= v.gety();
	return *this;
}

Vec2& Vec2::operator*=( float v ) {
	x *= v;
	y *= v;
	return *this;
}

Vec2& Vec2::operator/( float v ) {
	x /= v;
	y /= v;
	return *this;
}

Vec2 operator+( Vec2 const& u , Vec2 const& v ) {
	return Vec2(u.getx()+v.getx(), u.gety()+v.gety());
}

Vec2 operator-( Vec2 const& u , Vec2 const& v ) {
	return Vec2(u.getx()-v.getx(), u.gety()-v.gety());
}

Vec2 operator*( Vec2 const& v , float s ) {
	return Vec2(v.getx()*s, v.gety()*s);
}

Vec2 operator/( Vec2 const& v , float s ) {
	return Vec2(v.getx()/s, v.gety()/s);
}
Vec2 operator*( float s , Vec2 const& v ) {
	return Vec2(v.getx()*s, v.gety()*s);
}
