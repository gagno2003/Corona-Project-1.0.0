#include "MainWindow.h"

SDL_Rect srcF, destF;
SDL_Rect srcS, destS;
SDL_Rect srcT, destT;
SDL_Rect srcR, destR;
SDL_Renderer* MainWindow::renderer = nullptr;
SDL_Event MainWindow::event;
bool MainWindow::isRunning;
SDL_Window* MainWindow::window;
SDL_Texture* mouse;
SDL_Rect mouseRect;


MainWindow::MainWindow()
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		isRunning = true;
	}

	//first button
	firstbuttontexture = TextureManager::LoadTexture("Button/FirstButton.png");
	//first button

	//second button
	secondbuttontexture = TextureManager::LoadTexture("Button/SecondButton.png");
	//second button

	//third button
	thirdbuttontexture = TextureManager::LoadTexture("Button/ThirdButton.png");
	//third button

	//fourth button
	fourthbuttontexture = TextureManager::LoadTexture("Button/FourthButton.png");
	//fourth button

	//background 
	bgtexture = TextureManager::LoadTexture("Background/bg.png");
	//background

}

void MainWindow::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}



void MainWindow::render()
{

	destF.w = destS.w = destT.w = destR.w = 218;
	destF.h = destS.h = destT.h = destR.h = 43;
	destF.x = destS.x = destT.x = destR.x = 100;

	destF.y = 86;
	destS.y = 215;
	destT.y = 301;
	destR.y = 385;

	mouseRect.h = 32;
	mouseRect.w = 32;
	mouseRect.x = event.motion.x;
	mouseRect.y = event.motion.y;

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bgtexture, NULL, NULL);
	SDL_RenderCopy(renderer, firstbuttontexture, NULL, &destF);
	SDL_RenderCopy(renderer, secondbuttontexture, NULL, &destS);
	SDL_RenderCopy(renderer, thirdbuttontexture, NULL, &destT);
	SDL_RenderCopy(renderer, fourthbuttontexture, NULL, &destR);
	SDL_RenderCopy(renderer, mouse, NULL, &mouseRect);
	SDL_RenderPresent(renderer);
}

void MainWindow::events()
{
	
	StatisticWindows statistic;
	RecomendationsWindows recomendations;
	MythsWindows myths;
	RulesWindows rules;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_HasIntersection(&mouseRect, &destF))
			{
				firstbuttontexture = TextureManager::LoadTexture("Button/FirstButton2.png");
			}
			else
				firstbuttontexture = TextureManager::LoadTexture("Button/FirstButton.png");
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_HasIntersection(&mouseRect, &destF))
			{
				SDL_ShowCursor(true);
				statistic.DeathCasesstatistic();
				SDL_DestroyWindow(RecomendationsWindows::BothWindow);
				SDL_DestroyWindow(MythsWindows::MythWindow);
			}
		default:
			break;
		}
	}

	if (SDL_PollEvent(&MainWindow::event))
	{
		switch (MainWindow::event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_HasIntersection(&mouseRect, &destS))
			{
		
				secondbuttontexture = TextureManager::LoadTexture("Button/SecondButton2.png");

			}
			else
				secondbuttontexture = TextureManager::LoadTexture("Button/SecondButton.png");
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_HasIntersection(&mouseRect, &destS))
			{
				recomendations.BothRecomendation();
				SDL_DestroyWindow(StatisticWindows::DeathCasesWindow);
				SDL_DestroyWindow(MythsWindows::MythWindow);
			}
		default:
			break;
		}
	}

	if (SDL_PollEvent(&MainWindow::event))
	{
		switch (MainWindow::event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_HasIntersection(&mouseRect, &destT))
			{
			
				thirdbuttontexture = TextureManager::LoadTexture("Button/ThirdButton2.png");

			}
			else
				thirdbuttontexture = TextureManager::LoadTexture("Button/ThirdButton.png");
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_HasIntersection(&mouseRect, &destT))
			{
				myths.Myth();
				SDL_DestroyWindow(StatisticWindows::DeathCasesWindow);
				SDL_DestroyWindow(RecomendationsWindows::BothWindow);
			}
		default:
			break;
		}
	}

	if (SDL_PollEvent(&MainWindow::event))
	{
		switch (MainWindow::event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_HasIntersection(&mouseRect, &destR))
			{
				fourthbuttontexture = TextureManager::LoadTexture("Button/FourthButton2.png");
			}
			else
				fourthbuttontexture = TextureManager::LoadTexture("Button/FourthButton.png");
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_HasIntersection(&mouseRect, &destR))
			{
				rules.Rules();
				SDL_DestroyWindow(StatisticWindows::DeathCasesWindow);
				SDL_DestroyWindow(RecomendationsWindows::BothWindow);
				SDL_DestroyWindow(MythsWindows::MythWindow);
			}
		default:
			break;
		}
	}
}

void MainWindow::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
