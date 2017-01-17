#include "Mariposa.h"


Mariposa::Mariposa(PlayPG*est,JuegoPG*jogo, int px, int py) : ObjetoPG(jogo, px, py)
{
	visible = true;
	textura = TMariposa;
	estado = est;
	rect.h = juego->getTextura(textura)->gety();
	rect.w = juego->getTextura(textura)->getx()*3;
	cacho.x = 0;
	cacho.y = 0;
	cacho.w = juego->getTextura(textura)->getx();
	cacho.h = juego->getTextura(textura)->gety();
	puntos = 0;
	srand(1);
}


Mariposa::~Mariposa()
{
}

bool Mariposa::onClick(){
	//falta q con cada click cambio de pos
	juego->getMousePos(x, y);
	if (dentro(x, y)){
		
		rect.x = rand() % 770;
		rect.y = rand() % 770;
		numClicks++;
		if (numClicks == 3){
			estado->newPremio();
			numClicks = 0;
		}
		return true;
	}
	return false;
	
}

void Mariposa::update(){
	posicion++;
	cacho.x = cacho.x + 50;
	if (cacho.x >= 150)cacho.x = 0;
	rect.x -= 30;
	rect.y -= 30;
	if (rect.x <= 0)
		rect.x = rand() % 770;
	if (rect.y <= 0)
		rect.y = rand() % 770;
}
void Mariposa::draw(){
	juego->getTextura(textura)->draw(juego->getRender(),cacho,rect);
}