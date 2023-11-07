#include <cmath>
#include <cstdlib>
#include "tuples.hpp"

#define EPSILON 0.00001

bool compareDouble(double a, double b) {
	return abs(a - b) < EPSILON;
}

BaseTuple::BaseTuple() : a{0.0, 0.0, 0.0, 0.0} {}

BaseTuple::BaseTuple(double a, double b, double c, double d)
  : a{a, b, c, d} {}
	
double BaseTuple::operator[](int index) const {
	return a[index];
}
	
bool BaseTuple::operator==(const BaseTuple& rhs) const {
	return compareDouble(a[0], rhs[0])
		&& compareDouble(a[1], rhs[1])
		&& compareDouble(a[2], rhs[2])
		&& compareDouble(a[3], rhs[3]);
}

BaseTuple BaseTuple::operator+(const BaseTuple& rhs) const {
	return Tuple(a[0] + rhs[0],
		a[1] + rhs[1],
		a[2] + rhs[2],
		a[3] + rhs[3]);
}

BaseTuple BaseTuple::operator-(const BaseTuple& rhs) const {
	return Tuple(a[0] - rhs[0],
		a[1] - rhs[1],
		a[2] - rhs[2],
		a[3] - rhs[3]);
}

BaseTuple BaseTuple::operator-() const {
	BaseTuple zero;
	return zero - *this;
}

BaseTuple BaseTuple::operator*(double scalar) const {
	return Tuple(a[0] * scalar,
		a[1] * scalar,
		a[2] * scalar,
		a[3] * scalar);
}

BaseTuple BaseTuple::operator/(double scalar) const {
	return Tuple(a[0] / scalar,
		a[1] / scalar,
		a[2] / scalar,
		a[3] / scalar);
}
	
Tuple::Tuple() : BaseTuple(0.0, 0.0, 0.0, 0.0) {}

Tuple::Tuple(double x, double y, double z, double w)
: BaseTuple(x, y, z, w) {}

double Tuple::getX() {
  return a[0];
}

double Tuple::getY() {
  return a[1];
}

double Tuple::getZ() {
  return a[2];
}

double Tuple::getW() {
  return a[3];
}

double Tuple::magnitude() {
	return sqrt(a[0] * a[0] 
		+ a[1] * a[1] 
		+ a[2] * a[2] 
		+ a[3] * a[3]);
}

Tuple Tuple::normalize() {
	auto m = magnitude();
	return Tuple(getX() / m,
		getY() / m,
		getZ() / m,
		getW() / m);
}

double Tuple::dot(const Tuple& rhs) {
	return a[0] * rhs[0]
		+ a[1] * rhs[1]
		+ a[2] * rhs[2]
		+ a[3] * rhs[3];
}

Tuple Tuple::cross(const Tuple& b) {
	return Tuple(
		a[1] * b[2] - a[2] * b[1],
		a[2] * b[0] - a[0] * b[2],
		a[0] * b[1] - a[1] * b[0],
		0.0);
}

bool Tuple::isVector() {
	return a[3] == 0.0;
}

bool Tuple::isPoint() {
	return a[3] == 1.0;
}

Point::Point() : Tuple(0.0, 0.0, 0.0, 1.0) {}

Point::Point(double x, double y, double z)
: Tuple(x, y, z, 1.0) {}

Vector::Vector() : Tuple(0.0, 0.0, 0.0, 0.0) {}

Vector::Vector(double x, double y, double z)
: Tuple(x, y, z, 0.0) {}

Color::Color() : BaseTuple(0.0, 0.0, 0.0, 0.0) {}

Color::Color(double red, double green, double blue)
: BaseTuple(red, green, blue, 0.0) {}

double Color::getRed() {
  return a[0];
}

double Color::getGreen() {
  return a[1];
}

double Color::getBlue() {
  return a[2];
}

Color Color::operator*(Color& rhs) {
	return Color(getRed() * rhs.getRed(),
		getGreen() * rhs.getGreen(),
		getBlue() * rhs.getBlue());
}