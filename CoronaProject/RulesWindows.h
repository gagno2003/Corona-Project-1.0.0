#pragma once
#include "MainWindow.h"
class RulesWindows
{
public:
	RulesWindows();
	~RulesWindows();

	void Rules();


	static SDL_Window* RulesWindow;

private:


	SDL_Texture* RulesTexture;
	SDL_Renderer* RulesRenderer;


};

