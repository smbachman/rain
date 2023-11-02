#include <cmath>
#include <cstdlib>
#include "tuples.hpp"

#define EPSILON 0.00001

bool compareDouble(double a, double b) {
	return abs(a - b) < EPSILON;
}

Tuple::Tuple() : x(0.0), y(0.0), z(0.0), w(0.0) {}

Tuple::Tuple(double x, double y, double z, double w)
  : x(x), y(y), z(z), w(w) {}
	
bool Tuple::operator==(const Tuple& rhs) const {
	return compareDouble(x, rhs.x)
		&& compareDouble(y, rhs.y)
		&& compareDouble(z, rhs.z)
		&& compareDouble(w, rhs.w);
}

Tuple Tuple::operator+(const Tuple& rhs) const {
	return Tuple(x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w);
}

Tuple Tuple::operator-(const Tuple& rhs) const {
	return Tuple(x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w);
}

Tuple Tuple::operator-() const {
	Tuple zero;
	return zero - *this;
}

Tuple Tuple::operator*(double scalar) const {
	return Tuple(x * scalar,
		y * scalar,
		z * scalar,
		w * scalar);
}

Tuple Tuple::operator/(double scalar) const {
	return Tuple(x / scalar,
		y / scalar,
		z / scalar,
		w / scalar);
	}

double Tuple::getX() {
  return x;
}

double Tuple::getY() {
  return y;
}

double Tuple::getZ() {
  return z;
}

double Tuple::getW() {
  return w;
}

double Tuple::magnitude() {
	return sqrt(x*x + y*y + z*z + w*w);
}

Tuple Tuple::normalize() {
	return *this / magnitude();
}

double Tuple::dot(const Tuple& rhs) {
	return x * rhs.x
		+ y * rhs.y
		+ z * rhs.z
		+ w * rhs.w;
}

Tuple Tuple::cross(const Tuple& b) {
	return Tuple(
		y * b.z - z * b.y,
		z * b.x - x * b.z,
		x * b.y - y * b.x,
		0.0);
}

bool Tuple::isVector() {
	return w == 0.0;
}

bool Tuple::isPoint() {
	return w == 1.0;
}

Point::Point() : Tuple(0.0, 0.0, 0.0, 1.0) {}

Point::Point(double x, double y, double z)
: Tuple(x, y, z, 1.0) {}

Vector::Vector() : Tuple(0.0, 0.0, 0.0, 0.0) {}

Vector::Vector(double x, double y, double z)
: Tuple(x, y, z, 0.0) {}