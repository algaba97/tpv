#pragma once
#include "SDL_ttf.h"
#include <string>
class FuenteSDL
{
public:
	FuenteSDL();
	~FuenteSDL();
	void load(std::string  nombreArchivo, int tam);
	void close();
	SDL_Surface* textSolid(std::string texto, SDL_Color color);
private:
	TTF_Font * p;
};

