
#include "JuegoPG.h"
#include <iostream>
#include "SDL.h"
#include "vector"
#include "Premio.h"
#include "GlobosPG.h"
#include "Mariposa.h"
#include "GloboA.h"
#include <stdio.h>

#include "TexturasSDL.h"
#include <SDL_ttf.h>
#include "EstadoJuego.h"
#include "EstadoPG.h"
#include "MenuPG.h"
#include <stack>
using namespace std;

//onstructora que Los atributos se deben
//inicializar en el orden necesario :
// 1- El renderizador
// 2 - Las texturas, hace falta el renderizador para load()
// 3 - Los objetos, hacen falta las texturas para la constructora
JuegoPG::JuegoPG()
{

	
	direcciones.resize(7);
	direcciones[0] = "fondo.png";
	direcciones[1] = "globo.png";
	direcciones[2] = "globo2.png";
	direcciones[3] = "mariposa.png";
	direcciones[4] = "premio.png";
	direcciones[5] = "a.tff";
	direcciones[6] = "boton.png";
	initSDL();
	initMedia();
	srand(1);
	//Crea el fondo


	fin = false;
	gameOver = false;
	contador = 0;
	error = false;
	exit = false;
	pausa = false;
	c.r = 29;
	c.g = 100;
	c.b = 220;
	c.a = 100;
	estado.push(new PlayPG(this));

	//pFont = TTF_OpenFont("..\\bmps\\lazy.ttf", 28);
	
}
//La destructora.Los atributos se deben liberar en el orden
//contrario al que se inicializaron :
// 1 - Los objetos
// 2 - Las texturas
// 3 - El renderizador

JuegoPG::~JuegoPG()
{
	//closeSDL();
	//freeGlobos();
	textura[3]->closeFuente();
	int largo = textura.size();
	for (int i = 0; i < largo; i++){
		delete textura[i];
	}
	
	//TTF_Close(pFont);
}


void JuegoPG::run(){
	Uint32 lastUpdate = SDL_GetTicks();
	int MSxUpdate = 500;
	while (true){
		if (SDL_GetTicks() - lastUpdate >= MSxUpdate){
			topEstado()->update();
			render();
		}
	}
	/*
	bool fin = false;
	int pausa = 1;
	if (!error) {
		// Uint32 MSxUpdate = 500;  

		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		// Para depurar despues hay que crearlo por ahi;


		SDL_HideWindow(window);// Desactiva la pantalla para que no se vea el juego, lo hacemos para saber que ya esta cargado pero no queremos verlo

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Pincha Globos", "Estas preparado?", nullptr);// Pestaña que para todo hasta que pulses ok
		SDL_ShowWindow(window);//activa de nuevo la pantalla
		render();
		handle_event(pausa);
		int MSxUpdate = 500;// Mirar comentario de abajo |
		//                           V
		while (!exit && !gameOver) {
			//Hay que asignar MSxUpdate que es el tiempo de refresco
			//	cout << SDL_GetTicks()<<" " << lastUpdate<<"\n";
			
			if (pausa&&SDL_GetTicks() - lastUpdate >= MSxUpdate){// while(elapsed >= MSxUpdate)
				update();
				cout << "update";
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event(pausa);
			//para mirar si todos están destruidos
			for (int i = 0; i < globos; i++){
				if (!dynamic_cast<ObjetoPG*>(Objetos[i])->destruido())fin = false;
			}
			if (fin){ // Aquí poner condicion de parada

				
				
				string buffer = "Puntuacion : ";
				buffer += to_string(contador);

				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Pincha Globos", buffer.c_str(), nullptr);
				cout << buffer;;
				gameOver = true;
			}
			fin = true;
		}
		if (exit) cout << "EXIT \n";
		else cout << "Has obtenido " << contador << "puntos\n";
		SDL_Delay(200); //cin.get();
	}
	*/
}
void JuegoPG::render(){
	topEstado()->draw();
}


void JuegoPG::handle_event(int &pausa) {
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) exit = true;// Salir del juego
		else if (e.type == SDL_KEYUP &&e.key.keysym.sym == SDLK_p){
			if (pausa)pausa = false;
			else pausa = true;
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT)//pinchar con el boton izquierdo
				onClick(e.button.x, e.button.y);
		}
	}

}

void JuegoPG::update(){
	topEstado()->update();
}

//Metodo que ocurre cuando pinchas con el boton izquierdo
void JuegoPG::onClick(int pmx, int pmy){
	mousex = pmx;
	mousey = pmy;
	//Aquí va un bucle que pasa por los onCLiks de todos los objetos
	topEstado()->update();
}
	
bool JuegoPG::initSDL() {

	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		window = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (window == nullptr){
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (renderer == nullptr){
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

void JuegoPG::closeSDL() {

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}



SDL_Renderer* JuegoPG::getRender() const{
	return renderer;
}
// tendrás que añadir atributos para la posición del ratón(que deben actualizarse en onClick)
void JuegoPG::getMousePos(int & mpx, int & mpy) const{
	mpx = mousex;
	mpy = mousey;
}




// carga las texturas en el vector de texturas (fuente y música)
void JuegoPG::initMedia(){
	for (int i = 0; i < 7; i++)
	{
		textura.push_back(new TexturasSDL());
		textura[i]->load(renderer, direcciones[i]);
	}
} 	

//crea los differentes objetos como globos mas globos unos pocos mas de globos y si eso una mariposa y un premio
void JuegoPG::freeMedia(){
	textura[3]->closeFuente();
	int largo = textura.size();
	for (int i = 0; i < largo; i++){
		delete textura[i];
	}
	//borramos los globos
	largo = estado.size();
	for (int x = 0; x < largo; x++){
		estado.pop();
	}
}
void JuegoPG::changeState(EstadoJuego*newSt){

	estado.pop();
	estado.push(newSt);

}
EstadoJuego*  JuegoPG::topEstado(){
	return estado.top();
}
void JuegoPG::pushState(EstadoJuego* newState){
	estado.push(newState);
}
void JuegoPG::popState(){
	estado.pop();
}
void JuegoPG::setSalir(){
	freeMedia();
	closeSDL();
}