#pragma once
#include "MainWindow.h"
class StatisticWindows
{
public:
	StatisticWindows();
	~StatisticWindows();

	void DeathCasesstatistic();
	static SDL_Window* DeathCasesWindow;
	
private:

	//Death
	SDL_Texture* DeathCasesTexture;
	SDL_Renderer* DeathCasesRenderer;
	//Death

};

