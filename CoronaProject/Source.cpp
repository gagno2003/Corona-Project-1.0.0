#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "MainWindow.h"
using namespace std;
MainWindow* mainwindow = nullptr;



int main(int argc, char* argv[]) {

	mainwindow = new MainWindow();

	mainwindow->init("Corona", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 418, 500, false);

	while (mainwindow->running())
	{
		mainwindow->handleEvents();
		mainwindow->render();
		mainwindow->events();
	}

	mainwindow->clean();


	return 0;
}
