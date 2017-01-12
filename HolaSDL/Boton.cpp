#include "Boton.h"


Boton::Boton(CallBack_t* callback,JuegoPG*jogo, int px, int py) : ObjetoPG(jogo, px, py)
{
	visible = true;
	textura = TBoton;
	cb = callback;
	rect.h = juego->getTextura(textura)->getx();
	rect.w = juego->getTextura(textura)->gety();
}


Boton::~Boton()
{
}
bool Boton::onClick(){
	juego->getMousePos(x, y);
	if (dentro(x, y)){ 
		
		cb(juego);
		return true;
	}
	return false;
}