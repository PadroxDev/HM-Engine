#pragma once
#include <iostream>

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

	Vector2();
	Vector2(float _x, float _y);
	~Vector2();

	Vector2 operator+(Vector2 const& vec);
	Vector2 operator-(Vector2 const& vec);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);
	Vector2& operator+=(Vector2 const& vec);
	Vector2& operator-=(Vector2 const& vec);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
};