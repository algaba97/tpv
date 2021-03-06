
#ifndef JUEGOPG_H
#define JUEGOPG_H
#include "SDL.h"

#include "TexturasSDL.h"
#include <vector>
#include "ObjetoJuego.h"
#include "EstadoJuego.h"
#include <stack>


using namespace std;

enum Texturas_t{
	TFondo = 0, TGlobo1 = 1, TGlobo2 = 2, TMariposa = 3, TPremio = 4, TBoton = 5
};

class JuegoPG
{
public:
	
	JuegoPG();
	~JuegoPG();
	void run();
	bool initSDL();
	void closeSDL();
	void render();
	void SDL_RenderCopy(SDL_Renderer* pRenderer, SDL_Texture* pTexture, SDL_Rect rect, SDL_Surface renderRect);
	void onClick(int pmx, int pmy);
	void update();
	void handle_event(int &pausa);
	SDL_Color c;
	int pausa;
	TexturasSDL* getTextura(Texturas_t et) const { return textura[et]; };//��mirar q es texturas!!
	SDL_Renderer* getRender() const;
	void getMousePos(int & mpx, int & mpy) const; // tendr�s que a�adir atributos para la posici�n del rat�n(que deben actualizarse en onClick)
	
	void initMedia(); // carga las texturas en el vector de texturas (fuente y m�sica)
	void freeMedia();

	SDL_Window* getWindow(){ return window; }
	EstadoJuego* topEstado();
	
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir();
	int getAncho(){ return ancho; }
	int getAlto(){ return alto; }
private:
	
	Texturas_t texturas;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Color color;
	int const ancho = 800, alto = 600;
	vector<TexturasSDL*> textura;
	vector<string> direcciones;
	int globos = 4;
	bool error;
	bool exit;
	int contador;
	bool gameOver;
	int mousex, mousey;
	bool fin;
	stack<EstadoJuego*> estado;


};
#endif
