
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
	void render() const;
	void SDL_RenderCopy(SDL_Renderer* pRenderer, SDL_Texture* pTexture, SDL_Rect rect, SDL_Surface renderRect);
	void onClick(int pmx, int pmy);
	void update();
	void handle_event(int &pausa);
	SDL_Color c;
	int pausa;
	TexturasSDL* getTextura(Texturas_t et) const { return textura[et]; };//¡¡mirar q es texturas!!
	SDL_Renderer* getRender() const;
	void getMousePos(int & mpx, int & mpy) const; // tendrás que añadir atributos para la posición del ratón(que deben actualizarse en onClick)
	void newBaja(ObjetoJuego* po); // Los objetos informarán al juego cuando causen baja
	void newPuntos(ObjetoJuego* po); // Los objetos informarán al juego cuando se obtengan puntos
	void newPremio(); // Los objetos informará al juego cuando se obtenga un premio
	void initMedia(); // carga las texturas en el vector de texturas (fuente y música)
	void freeMedia();
	void initObjetos();
	SDL_Window* getWindow(){ return window; }
	EstadoJuego* topEstado();
	
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir();

private:
	
	Texturas_t texturas;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Color color;
	
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
