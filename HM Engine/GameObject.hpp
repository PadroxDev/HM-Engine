#pragma once
#include <vector>
#include "Vector.hpp"

typedef struct Component;
typedef struct SDL_Renderer;

class Transform
{
private:

public:
	Vector2 Position;
	Vector2 Size;
	float Rotation;

	Transform();
	~Transform();

	void Reset();
};

class GameObject
{
protected:
	std::vector<Component*> components;

public:
	Transform transform;
	
	GameObject();
	GameObject(Vector2 pos);
	GameObject(Vector2 pos, Vector2 size);
	GameObject(Vector2 pos, float rotation);
	GameObject(Vector2 pos, Vector2 size, float rotation);
	~GameObject();

	virtual void Update(double dT);
	virtual void Render(SDL_Renderer* renderer);
	
	void ResetTransform();
};