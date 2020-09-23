#pragma once
#include "MainWindow.h"
class MythsWindows
{
public:
	MythsWindows();
	~MythsWindows();

	void Myth();


	static SDL_Window* MythWindow;

private:


	SDL_Texture* MythTexture;
	SDL_Renderer* MythRenderer;


};

