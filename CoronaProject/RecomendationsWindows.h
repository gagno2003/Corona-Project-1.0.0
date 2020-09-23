#pragma once
#include "MainWindow.h"
class RecomendationsWindows
{
public:
	RecomendationsWindows();
	~RecomendationsWindows();

	void BothRecomendation();

	static SDL_Window* BothWindow;

private:

	SDL_Texture* BothTexture;
	SDL_Renderer* BothRenderer;

};

