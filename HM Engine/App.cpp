#include "App.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Sprite.hpp"

App::App() : window(nullptr), renderer(nullptr), running(false), currentPerformance(0),
	lastPerformance(0), deltaTime(0), fps(0)
{}

App::~App() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void App::Run(AppWindowParams params) {
	if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
		std::cout << "SDL failed to initialize!\nError: " << SDL_GetError() << std::endl;
		exit(1);
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
		std::cout << "SDL_Image failed to initialize properly!\nError: " << IMG_GetError() << std::endl;
		exit(1);
	}

	int mixFlags = MIX_INIT_MP3;
	if ((Mix_Init(mixFlags) & mixFlags) != mixFlags) {
		std::cout << "SDL_Mixer failed to initialize properly!\nError: " << Mix_GetError() << std::endl;
		exit(1);
	}

	if (TTF_Init() != 0) {
		std::cout << "SDL_TTF failed to initialize properly!\nError: " << TTF_GetError() << std::endl;
		exit(1);
	}

	window = SDL_CreateWindow(params.title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, params.width, params.height, params.windowFlags);

	if (!window) {
		std::cout << "Window creation failed!" << std::endl;
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, params.rendererFlags);
	if (!renderer) {
		std::cout << "Renderer creation failed!" << std::endl;
		exit(1);
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	running = true;
	currentPerformance = SDL_GetPerformanceCounter();
	gameObjects.clear();
	Sprite sprite("res/img/test.png", renderer);
	gameObjects.push_back(sprite);

	while (running) {
		HandleInput();
		Update();
		Render();
	}
}

void App::HandleInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
	}
}

void App::Update() {
	lastPerformance = currentPerformance;
	currentPerformance = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentPerformance - lastPerformance) / (double)SDL_GetPerformanceFrequency());
	fps = 1.0f / deltaTime;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Update(deltaTime);
	}
}

void App::Render() {
	SDL_RenderClear(renderer);
	
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Render(renderer);
	}
	
	SDL_RenderPresent(renderer);
}