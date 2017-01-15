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