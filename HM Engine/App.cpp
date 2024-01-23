#include "App.hpp"
#include <SDL.h>
#include <iostream>

App::App() : window(nullptr), renderer(nullptr), running(false), currentPerformance(0),
	lastPerformance(0), deltaTime(0), fps(0)
{}

App::~App() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void App::Run(AppWindowParams params) {
	if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
		std::cout << "SDL failed to initialize" << std::endl;
		return;
	}

	window = SDL_CreateWindow(params.title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, params.width, params.height, params.windowFlags);

	if (!window) {
		std::cout << "Window creation failed !" << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, params.rendererFlags);
	if (!renderer) {
		std::cout << "Renderer creation failed !" << std::endl;
		return;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	running = true;
	currentPerformance = SDL_GetPerformanceCounter();

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
}

void App::Render() {
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}