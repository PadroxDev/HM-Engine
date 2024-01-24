#include "Vector.hpp"

const Vector2 Vector2::Zero(0.0f, 0.0f);
const Vector2 Vector2::One(1.0f, 1.0f);
const Vector2 Vector2::Up(0.0f, 1.0f);
const Vector2 Vector2::Left(-1.0f, 0.0f);
const Vector2 Vector2::Right(1.0f, 0.0f);
const Vector2 Vector2::Down(0.0f, -1.0f);

Vector2::Vector2() : x(0), y(0)
{}

Vector2::Vector2(float _x, float _y) : x(_x), y(_y)
{}

Vector2::~Vector2()
{}

Vector2 Vector2::operator+(Vector2 const& vec) {
	return Vector2(
		x + vec.x,
		y + vec.y
	);
}

Vector2 Vector2::operator-(Vector2 const& vec) {
	return Vector2(
		x - vec.x,
		y - vec.y
	);
}

Vector2 Vector2::operator*(double const& scalar) {
	return Vector2(
		x * scalar,
		y * scalar
	);
}

Vector2 Vector2::operator/(double const& scalar) {
	return Vector2(
		x / scalar,
		y / scalar
	);
}