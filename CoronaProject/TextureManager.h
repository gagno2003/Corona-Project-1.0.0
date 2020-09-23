#pragma once
#include "MainWindow.h"
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* LoadTexture(const char* texture);
	static SDL_Texture* LoadTextureWithRenderer(const char* texture, SDL_Renderer* renderer);
};

