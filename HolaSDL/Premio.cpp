#include "Premio.h"


Premio::Premio(JuegoPG*jogo, int px, int py) : ObjetoPG(jogo,x,y)
{
	textura = TPremio;
	visible = false;
	rect.h = juego->getTextura(textura)->getx() / 9;
	rect.w = juego->getTextura(textura)->gety() / 9;
	puntos = 20;
	ticks = 0;
}


Premio::~Premio()
{
}

bool Premio::onClick(){
	
	juego->getMousePos(x, y);
	if (visible && dentro(x, y)){
		cout << "Premio";
		damePuntos();
		juego->newPuntos(this);
		
		reinicio();
		return true;
	}
	else return false;
}
void Premio::update(){
	if (visible){
		ticks++;
		if (puntos > 5)puntos -= 5;
	}
	if (ticks == 3){
		puntos = 20;
		rect.x = rand() % 770;
		rect.y = rand() % 770;
		visible = false;
	}
//esperar a los tres frames de vida
}
void Premio::reinicio(){
	if (visible == true){
		visible = false;
		rect.x = rand() % 770;
		rect.y = rand() % 770;
		puntos = 20;
	}

}