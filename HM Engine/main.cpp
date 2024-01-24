#include <SDL.h>
#include <iostream>
#include "App.hpp"
#include "Mathf.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	AppWindowParams params = {
		"MH Engine Application Window",
		1280, 720,
		SDL_WINDOW_ALLOW_HIGHDPI,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	};
	App().Run(params);

	return 0;
}