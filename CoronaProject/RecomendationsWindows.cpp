#include "RecomendationsWindows.h"

SDL_Window* RecomendationsWindows::BothWindow;

RecomendationsWindows::RecomendationsWindows()
{
}

RecomendationsWindows::~RecomendationsWindows()
{
}

void RecomendationsWindows::BothRecomendation()
{
	//Create Window
	BothWindow = SDL_CreateWindow("Recomendations", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 412, 530, SDL_WINDOW_ALLOW_HIGHDPI);
	//Create Window

	//Create Renderer
	BothRenderer = SDL_CreateRenderer(BothWindow, -1, 0);
	//Create Renderer

	//Create Background
	BothTexture = TextureManager::LoadTextureWithRenderer("Recomendations/recomendations.png", BothRenderer);
	//Create Background


	//Add Images
	SDL_RenderCopy(BothRenderer, BothTexture, NULL, NULL);
	SDL_RenderPresent(BothRenderer);
	SDL_RenderClear(BothRenderer);
	//Add Images
}
