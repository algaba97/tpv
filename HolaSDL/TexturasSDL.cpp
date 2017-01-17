
#include "TexturasSDL.h"
#include <iostream>
#include "SDL.h"
#include <SDL_ttf.h>
#include "SDL_image.h"
#include "Error.h"
using namespace std;


TexturasSDL::TexturasSDL()
{
	
	textura = nullptr;
}


TexturasSDL::~TexturasSDL()
{
	
	SDL_DestroyTexture(textura);
	textura = nullptr;
	
}
void TexturasSDL::render(SDL_Renderer*render, int px, int py){
	SDL_Rect rect;
	rect.x = px;
	rect.y = py;
	rect.w = 100;
	rect.h = 100;
	SDL_RenderCopy(render, textura, nullptr, &rect);

}

bool TexturasSDL::load(SDL_Renderer*render, string const& nombArch){

	//The image we will load 

	std::string bmpName{ nombArch };

	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load image
	pTempSurface = IMG_Load(bmpName.c_str());
	
	if (pTempSurface == nullptr) {
		cout << "Unable to load image " << bmpName << "! \nSDL Error: " << SDL_GetError() << '\n';
	    //throw errorTextura("Unable to load image");

		success = false;
	}
	else {
		alto = pTempSurface->w;
		ancho = pTempSurface->h;
		SDL_DestroyTexture(textura);
		textura = SDL_CreateTextureFromSurface(render, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		success = textura != nullptr;
	}

	return success;
}
void TexturasSDL::draw(SDL_Renderer*render,SDL_Rect const & rect){
	SDL_RenderCopy(render, textura, nullptr, &rect);

}
void TexturasSDL::draw(SDL_Renderer*render, SDL_Rect const & cacho, SDL_Rect const & rect){
	SDL_RenderCopy(render, textura, &cacho, &rect);

}
void TexturasSDL::draw(SDL_Renderer*render){
	SDL_RenderCopy(render, textura, nullptr, nullptr);

}
bool TexturasSDL::load(SDL_Renderer*render, string const& nombArch, SDL_Color const& colKey){
	return true;
}

int TexturasSDL::getx(){
	return ancho;
}

int TexturasSDL::gety(){
	return alto;
}


//Se inicia y cierra en el propio metodo así solo es usado cuando se llama al metodo 
//es ampliable a varias fuentes y palabras.
bool TexturasSDL::loadFromText(SDL_Renderer * render, string texto, SDL_Color color) {
	loadFuente("a.ttf", 30);
	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load image

	pTempSurface = font.textSolid(texto, color);
	
	if (pTempSurface == nullptr) {
		cout << "Unable to load image ";
		success = false;
	}
	else {
		textura = SDL_CreateTextureFromSurface(render, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		success = textura != nullptr;
	}

	return success;
}
FuenteSDL TexturasSDL::font;
bool TexturasSDL::loadFuente(std::string nombreArchivo, int tam){
	font.load(nombreArchivo, tam);
	return true;
}

void TexturasSDL::closeFuente(){
	font.close();
}

void TexturasSDL::renderText(SDL_Renderer * render, std::string texto){
	SDL_Color color;
	color.r = 100;
	color.g = 50;
	color.b = 100;
	SDL_Rect rect;
	rect.h = 20;
	rect.w = 20;
	rect.x = 25;
	rect.y = 25;
	loadFromText(render, texto, color);
	SDL_RenderCopy(render, textura, nullptr, &rect);
}