#pragma once
#include "GameObject.hpp"
#include "Vector.hpp"
#include <string>

typedef struct SDL_Renderer;

class Sprite : public GameObject
{
protected:
	std::string path;
	SDL_Texture* imageTex;

public:
	Sprite(std::string path, SDL_Renderer* renderer);
	~Sprite();

	void Update(double dT) override;
	void Render(SDL_Renderer* renderer) override;
};