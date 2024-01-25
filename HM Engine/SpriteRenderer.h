#pragma once
#include "Component.h"

typedef struct SDL_Renderer;

class SpriteRenderer : public Component
{
protected:

public:
	SpriteRenderer();
	~SpriteRenderer();
	void Update(double dT) override;
	void Render(SDL_Renderer* renderer) override;
};