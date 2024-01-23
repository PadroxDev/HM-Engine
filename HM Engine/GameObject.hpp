#pragma once
#include "Vector.hpp"

class Transform
{
private:
	Vector2 position;
	float rotation;
	Vector2 size;

public:
	Vector2 Position() { return position; }
	float Rotation() { return rotation; }
	Vector2 Size() { return size; }
	void Reset();
};

class GameObject
{
protected:

public:
	Transform transform;

	void ResetTransform();
};