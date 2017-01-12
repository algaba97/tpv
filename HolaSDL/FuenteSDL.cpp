#include "FuenteSDL.h"
FuenteSDL::FuenteSDL()
{

	TTF_Init();
}


FuenteSDL::~FuenteSDL()
{
	TTF_Quit();
}

void FuenteSDL::load(std::string  nombreArchivo, int tam){
	p = TTF_OpenFont(nombreArchivo.c_str(), tam);
}

void FuenteSDL::close(){
	TTF_CloseFont(p);
}
SDL_Surface* FuenteSDL::textSolid(std::string texto, SDL_Color color){
	return	TTF_RenderText_Solid(p, texto.c_str(), color);
}