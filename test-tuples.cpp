#define CATCH_CONFIG_MAIN

#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include <cmath>
#include "catch.hpp"
#include "tuples.hpp"

TEST_CASE("A tuple with w=1.0 is a point", "[tuples]") {
  Tuple a(4.3, -4.2, 3.1, 1.0);
  REQUIRE( a.getX() == 4.3 );
  REQUIRE( a.getY() == -4.2 );
  REQUIRE( a.getZ() == 3.1 );
  REQUIRE( a.getW() == 1.0 );
  REQUIRE( a.isPoint() );
  REQUIRE( !a.isVector() );
}

TEST_CASE("A tuple with w=0.0 is a vector", "[tuples]") {
  Tuple a(4.3, -4.2, 3.1, 0.0);
  REQUIRE( a.getX() == 4.3 );
  REQUIRE( a.getY() == -4.2 );
  REQUIRE( a.getZ() == 3.1 );
  REQUIRE( a.getW() == 0.0 );
  REQUIRE( !a.isPoint() );
  REQUIRE( a.isVector() );
}

TEST_CASE("point creates tuples with w=1", "[tuples]") {
  Point p(4, -4, 3);
  REQUIRE( p == Tuple(4, -4, 3, 1) );
}

TEST_CASE("vector creates tuples with w=0", "[tuples]") {
  Vector v(4, -4, 3);
  REQUIRE( v == Tuple(4, -4, 3, 0) );
}

TEST_CASE("adding two tuples", "[tuples]") {
  Tuple a1(3, -2, 5, 1);
	Tuple a2(-2, 3, 1, 0);
  REQUIRE( a1 + a2 == Tuple(1, 1, 6, 1) );
}

TEST_CASE("Subtracting two points", "[tuples]") {
  Point p1(3, 2, 1);
	Point p2(5, 6, 7);
  REQUIRE( p1 - p2 == Vector(-2, -4, -6) );
}

TEST_CASE("Subtracting a vector from a point", "[tuples]") {
  Point p(3, 2, 1);
	Vector v(5, 6, 7);
  REQUIRE( p - v == Point(-2, -4, -6) );
}

TEST_CASE("Subtracting two vectors", "[tuples]") {
  Vector v1(3, 2, 1);
	Vector v2(5, 6, 7);
  REQUIRE( v1 - v2 == Vector(-2, -4, -6) );
}

TEST_CASE("Subtracting a vector from the zero vector", "[tuples]") {
  Vector zero;
	Vector v(1, -2, 3);
  REQUIRE( zero - v == Vector(-1, 2, -3) );
}

TEST_CASE("Negating a tuple", "[tuples]") {
  Tuple a(1, -2, 3, -4);
  REQUIRE( -a == Tuple(-1, 2, -3, 4) );
}

TEST_CASE("Multiplying a tuple by a scalar", "[tuples]") {
  Tuple a(1, -2, 3, -4);
  REQUIRE( a * 3.5 == Tuple(3.5, -7, 10.5, -14) );
}

TEST_CASE("Multiplying a tuple by a fraction", "[tuples]") {
  Tuple a(1, -2, 3, -4);
  REQUIRE( a * 0.5 == Tuple(0.5, -1, 1.5, -2) );
}

TEST_CASE("Dividing a tuple by a scalar", "[tuples]") {
  Tuple a(1, -2, 3, -4);
  REQUIRE( a / 2 == Tuple(0.5, -1, 1.5, -2) );
}

TEST_CASE("Computing the magnitude of vector(1, 0, 0)", "[tuples]") {
  Vector v(1, 0, 0);
  REQUIRE( v.magnitude() == 1 );
}

TEST_CASE("Computing the magnitude of vector(0, 1, 0)", "[tuples]") {
  Vector v(0, 1, 0);
  REQUIRE( v.magnitude() == 1 );
}

TEST_CASE("Computing the magnitude of vector(0, 0, 1)", "[tuples]") {
  Vector v(0, 0, 1);
  REQUIRE( v.magnitude() == 1 );
}

TEST_CASE("Computing the magnitude of vector(1, 2, 3)", "[tuples]") {
  Vector v(1, 2, 3);
  REQUIRE( v.magnitude() == sqrt(14) );
}

TEST_CASE("Computing the magnitude of vector(-1, -2, -3)", "[tuples]") {
  Vector v(-1, -2, -3);
  REQUIRE( v.magnitude() == sqrt(14) );
}

TEST_CASE("Normalizing vector(4, 0, 0) gives (1, 0, 0)", "[tuples]") {
  Vector v(4, 0, 0);
  REQUIRE( v.normalize() == Vector(1, 0, 0) );
}

TEST_CASE("Normalizing vector(1, 2, 3)", "[tuples]") {
  Vector v(1, 2, 3);
  REQUIRE( v.normalize() == Vector(0.26726, 0.53452, 0.80178) );
}

TEST_CASE("The magnitude of a normalized vector", "[tuples]") {
  Vector v(1, 2, 3);
	Tuple norm = v.normalize();
  REQUIRE( norm.magnitude() == 1 );
}

TEST_CASE("The dot product of two tuples", "[tuples]") {
  Vector a(1, 2, 3);
	Vector b(2, 3, 4);
  REQUIRE( a.dot(b) == 20 );
}

TEST_CASE("The cross product of two vectors", "[tuples]") {
  Vector a(1, 2, 3);
	Vector b(2, 3, 4);
  REQUIRE( a.cross(b) == Vector(-1, 2, -1) );
	REQUIRE( b.cross(a) == Vector(1, -2, 1) );
}

TEST_CASE("Colors are (red, green, blue) tuples", "[tuples]") {
  Color c(-0.5,0.4,1.7);
  REQUIRE( c.getRed() == -0.5 );
  REQUIRE( c.getGreen() == 0.4 );
  REQUIRE( c.getBlue() == 1.7 );
}

TEST_CASE("Adding colors", "[tuples]") {
  Color c1(0.9, 0.6, 0.75);
	Color c2(0.7, 0.1, 0.25);
  REQUIRE( c1 + c2 == Color(1.6, 0.7, 1.0) );
}

TEST_CASE("Subtracting colors", "[tuples]") {
  Color c1(0.9, 0.6, 0.75);
	Color c2(0.7, 0.1, 0.25);
  REQUIRE( c1 - c2 == Color(0.2, 0.5, 0.5) );
}

TEST_CASE("Multiplying a color by a scalar", "[tuples]") {
  Color c(0.2, 0.3, 0.4);
  REQUIRE( (BaseTuple)c * 2.0 == Color(0.4, 0.6, 0.8) );
}

// Scenario: Multiplying colors
//   Given c1 ← color(1, 0.2, 0.4)
//     And c2 ← color(0.9, 1, 0.1)
//    Then c1 * c2 = color(0.9, 0.2, 0.04)

TEST_CASE("Multiplying colors", "[tuples]") {
  Color c1(1, 0.2, 0.4);
	Color c2(0.9, 1, 0.1);
  REQUIRE( c1 * c2 == Color(0.9, 0.2, 0.04) );
}