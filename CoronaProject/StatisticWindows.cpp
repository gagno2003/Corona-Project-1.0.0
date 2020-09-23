#include "StatisticWindows.h"

SDL_Window* StatisticWindows::DeathCasesWindow;

SDL_Texture* Deathmouse;
SDL_Rect DeathmouseRect;
SDL_Texture* Casemouse;
SDL_Rect CasemouseRect;

StatisticWindows::StatisticWindows()
{
}

StatisticWindows::~StatisticWindows()
{
}

void StatisticWindows::DeathCasesstatistic()
{
	//Create Window
	DeathCasesWindow = SDL_CreateWindow("Death Statistic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 678, 500, SDL_WINDOW_ALLOW_HIGHDPI);
	//Create Window

	//Create Renderer
	DeathCasesRenderer = SDL_CreateRenderer(DeathCasesWindow, -1, 0);
	//Create Renderer

	//Create Background 
	DeathCasesTexture = TextureManager::LoadTextureWithRenderer("Statistic/statistic.png", DeathCasesRenderer);
	//Create Background


	//Add Images
	SDL_RenderCopy(DeathCasesRenderer, DeathCasesTexture, NULL, NULL);
	SDL_RenderPresent(DeathCasesRenderer);
	SDL_RenderClear(DeathCasesRenderer);
	//Add Images
}


