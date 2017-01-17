#ifndef TEXTURA_H
#define TEXTURA_H
#include "SDL.h"
#include <string>
#include <SDL_ttf.h>
#include "FuenteSDL.h"
#include "Error.h"
using namespace std;
class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	bool load(SDL_Renderer*render, string const& nombArch);
	void draw(SDL_Renderer*render,SDL_Rect const & rect);
	void draw(SDL_Renderer*render, SDL_Rect const & cacho, SDL_Rect const & rect);
	bool loadFromText(SDL_Renderer*render, string nombre, SDL_Color color);
	static bool loadFuente(std::string nombreArchivo,int tam);
	static void closeFuente();
	void render(SDL_Renderer*render, int px, int py);
	void TexturasSDL::draw(SDL_Renderer*render);
	void renderText(SDL_Renderer * render, std::string texto);
	SDL_Texture* dameTextura(){ return textura; }
	int getx();
	int gety();
	
	
private:
	
	int alto;
	int ancho;
	SDL_Texture*textura;
	static FuenteSDL font;
	bool load(SDL_Renderer*render, string const& nombArch, SDL_Color const& colKey);

};
#endif