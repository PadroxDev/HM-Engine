#pragma once

class Vector2
{
private:

public:
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 Up;
	static const Vector2 Left;
	static const Vector2 Right;
	static const Vector2 Down;

	float x;
	float y;

	Vector2(float _x, float _y);
	~Vector2();

	Vector2 operator+(Vector2 const& vec) {
		return Vector2(
			x + vec.x,
			y + vec.y
		);
	}

	Vector2 operator-(Vector2 const& vec) {
		return Vector2(
			x - vec.x,
			y - vec.y
		);
	}

	Vector2 operator*(float const& scalar) {
		return Vector2(
			x * scalar,
			y * scalar
		);
	}

	Vector2 operator/(float const& scalar) {
		return Vector2(
			x / scalar,
			y / scalar
		);
	}
};

const Vector2 Vector2::Zero = Vector2(0.0, 0.0);
const Vector2 Vector2::One = Vector2(1.0, 1.0);
const Vector2 Vector2::Up = Vector2(0.0, 1.0);
const Vector2 Vector2::Left = Vector2(-1.0, 0.0);
const Vector2 Vector2::Right = Vector2(1.0, 0.0);
const Vector2 Vector2::Down = Vector2(0.0, -1.0);