#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.hpp"
#include "Mathf.hpp"

Sprite::Sprite(std::string _path, SDL_Renderer* renderer) : GameObject(), path(_path), imageTex(nullptr)
{
	SDL_Surface* imageSurf = IMG_Load(path.c_str());
	if (imageSurf == nullptr) {
		std::cout << "Sprite's image failed to load!\nError: " << IMG_GetError() << std::endl;
		return;
	}
	imageTex = SDL_CreateTextureFromSurface(renderer, imageSurf);
	SDL_FreeSurface(imageSurf);
}

Sprite::~Sprite()
{}

void Sprite::Update(double dT) {

}

void Sprite::Render(SDL_Renderer* renderer) {
	SDL_Rect destRect = {
		transform.Position.x * Mathf::PixelsPerUnit,
		transform.Position.y * Mathf::PixelsPerUnit,
		transform.Size.x * Mathf::PixelsPerUnit,
		transform.Size.y * Mathf::PixelsPerUnit
	};
	SDL_RenderCopy(renderer, imageTex, nullptr, &destRect);
}