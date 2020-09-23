#include "MythsWindows.h"

SDL_Window* MythsWindows::MythWindow;


MythsWindows::MythsWindows()
{
}

MythsWindows::~MythsWindows()
{
}

void MythsWindows::Myth()
{
	//Create Window
	MythWindow = SDL_CreateWindow("Myths", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 552, 612, SDL_WINDOW_ALLOW_HIGHDPI);
	//Create Window

	//Create Renderer
	MythRenderer = SDL_CreateRenderer(MythWindow, -1, 0);
	//Create Renderer

	//Create Background
	MythTexture = TextureManager::LoadTextureWithRenderer("Myths/Myths.png", MythRenderer);
	//Create Background


	//Add Images
	SDL_RenderCopy(MythRenderer, MythTexture, NULL, NULL);
	SDL_RenderPresent(MythRenderer);
	SDL_RenderClear(MythRenderer);
	//Add Images
}



