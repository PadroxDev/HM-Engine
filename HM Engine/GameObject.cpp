#include "GameObject.hpp"

#pragma region Transform

Transform::Transform() : Position(Vector2::Zero), Size(Vector2::One), Rotation(0)
{}

Transform::~Transform()
{}

void Transform::Reset() {
	Position = Vector2::Zero;
	Rotation = 0;
	Size = Vector2::Zero;
}

#pragma endregion Transform

#pragma region GameObject

GameObject::GameObject(Vector2 pos, Vector2 size, float rotation)
{
	transform.Position = pos;
	transform.Size = size;
	transform.Rotation = rotation;
}

GameObject::GameObject() : GameObject(Vector2::Zero, Vector2::One, 0) {}
GameObject::GameObject(Vector2 pos) : GameObject(pos, Vector2::One, 0) {}
GameObject::GameObject(Vector2 pos, Vector2 size) : GameObject(pos, size, 0) {}
GameObject::GameObject(Vector2 pos, float rotation) : GameObject(pos, Vector2::One, rotation) {}

GameObject::~GameObject()
{}

void GameObject::Update(double dT) {
	std::cout << "Update isn't overrided !" << std::endl;
}

void GameObject::Render(SDL_Renderer* renderer) {
	std::cout << "Render isn't overrided !" << std::endl;
}

void GameObject::ResetTransform() {
	transform.Reset();
}

#pragma endregion GameObject