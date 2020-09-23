#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempsurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(MainWindow::renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return tex;
}

SDL_Texture* TextureManager::LoadTextureWithRenderer(const char* texture, SDL_Renderer* renderer)
{
	SDL_Surface* tempsurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return tex;
}
