#pragma once

typedef struct SDL_Renderer;

class Component {
protected:

public:
	Component();
	~Component();
	virtual void Update(double dT) = 0 {};
	virtual void Render(SDL_Renderer* renderer) = 0 {};
};