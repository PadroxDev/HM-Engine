#pragma once
#include <string>
#include <vector>
#include "GameObject.hpp"

class SDL_Window;
class SDL_Renderer;

struct AppWindowParams {
	std::string title;
	unsigned int width;
	unsigned int height;
	uint32_t windowFlags;
	uint32_t rendererFlags;
};

class App {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	uint64_t currentPerformance;
	uint64_t lastPerformance;
	double deltaTime;
	unsigned int fps;
	std::vector<GameObject> gameObjects;
	bool running;

public:
	App();
	~App();
	void Run(AppWindowParams params);
	void HandleInput();
	void Update();
	void Render();
};