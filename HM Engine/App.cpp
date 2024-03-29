#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <SDL_ttf.h>
#include "App.hpp"
#include "GameObject.hpp"
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
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

	running = true;
	currentPerformance = SDL_GetPerformanceCounter();
	gameObjects.clear();
	Sprite sprite("res/img/marly.png", renderer);
	sprite.transform.Size *= 2;
	gameObjects.push_back(&sprite);

	while (running) {
		HandleInput();
		Update();
		Render();
	}
}

void App::HandleInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_KEYDOWN:
			HandleKeyDown(event);
			break;
		case SDL_QUIT:
			running = false;
			break;
		}
	}
}

void App::HandleKeyDown(SDL_Event& event) {
	switch (event.key.keysym.sym) {
	case SDLK_d:
		gameObjects[0]->transform.Position += Vector2::Right;
		break;
	}
}

void App::Update() {
	lastPerformance = currentPerformance;
	currentPerformance = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentPerformance - lastPerformance) / (double)SDL_GetPerformanceFrequency());
	fps = 1.0f / deltaTime;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(deltaTime);
	}
}

void App::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Render(renderer);
	}
	
	SDL_RenderPresent(renderer);
}