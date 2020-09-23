#include "RulesWindows.h"

SDL_Window* RulesWindows::RulesWindow;

RulesWindows::RulesWindows()
{
}

RulesWindows::~RulesWindows()
{
}

void RulesWindows::Rules()
{
	//Create Window
	RulesWindow = SDL_CreateWindow("Rules", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 646, 616, SDL_WINDOW_ALLOW_HIGHDPI);
	//Create Window

	//Create Renderer
	RulesRenderer = SDL_CreateRenderer(RulesWindow, -1, 0);
	//Create Renderer

	//Create Background
	RulesTexture = TextureManager::LoadTextureWithRenderer("Rules/rules.png", RulesRenderer);
	//Create Background


	//Add Images
	SDL_RenderCopy(RulesRenderer, RulesTexture, NULL, NULL);
	SDL_RenderPresent(RulesRenderer);
	SDL_RenderClear(RulesRenderer);
	//Add Images
}