#define SDL_MAIN_HANDLED
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "RecomendationsWindows.h"
#include "StatisticWindows.h"
#include "MythsWindows.h"
#include "RulesWindows.h"
using namespace std;
class MainWindow
{
public:
	MainWindow();
	~MainWindow();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void render();
	void events();
	void clean();
	bool running() { return isRunning; }

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;
	static SDL_Window* window;
private:
	SDL_Texture* bgtexture;
	SDL_Texture* firstbuttontexture;
	SDL_Texture* secondbuttontexture;
	SDL_Texture* thirdbuttontexture;
	SDL_Texture* fourthbuttontexture;
};



