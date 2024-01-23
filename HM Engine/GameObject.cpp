#include "GameObject.hpp"

#pragma region Transform

void Transform::Reset() {
	position = Vector2::Zero;
	rotation = 0;
	size = Vector2::Zero;
}

#pragma endregion Transform

#pragma region GameObject

void GameObject::ResetTransform() {
	transform.Reset();
}

#pragma endregion GameObject