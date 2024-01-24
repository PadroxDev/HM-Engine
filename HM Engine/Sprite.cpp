#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.hpp"
#include "Mathf.hpp"

Sprite::Sprite(std::string _path, SDL_Renderer* renderer) : GameObject(), path(_path)
{
	SDL_Surface* image = IMG_Load(path.c_str());
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}

void Sprite::Update(double dT) {
	std::cout << "Updated !" << std::endl;
}

void Sprite::Render(SDL_Renderer* renderer) {
	SDL_Rect destRect = { transform.Position.x, transform.Position.y,
		transform.Size.x * Mathf::PixelsPerUnit,
		transform.Size.y * Mathf::PixelsPerUnit
	};
	SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, image), nullptr, &destRect);
}