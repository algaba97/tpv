#include "EstadoPG.h"


EstadoPG::EstadoPG(JuegoPG*Juego)
{
	juego = Juego;
}


EstadoPG::~EstadoPG()
{
}
 void EstadoPG::onClick(){
	 bool pinchado = false;
	 for (int i = 0; i < Objetos.size() && !pinchado; i++)
		 if (Objetos[i]->onClick())pinchado = true;
 
}
 void EstadoPG::draw(){
	  SDL_RenderClear(juego->getRender());
	  
	  for (int i = 0; i < Objetos.size(); i++)Objetos[i]->draw();
	  SDL_RenderPresent(juego->getRender());
 }