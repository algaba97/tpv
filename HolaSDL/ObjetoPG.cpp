#include "ObjetoPG.h"
using namespace std;

ObjetoPG::ObjetoPG(JuegoPG*jogo, int px, int py)
{
	juego = jogo;

	rect.x = px;
	rect.y = py;
	
	puntos = 5;
	 dest = false;
	 visible = true;
}


ObjetoPG::~ObjetoPG()
{

}

bool ObjetoPG::dentro(int x , int y)const {
	return  (visible && (rect.x <= x) && (x <= (rect.x + rect.w)) && (rect.y <= y) && (y <= (rect.y + rect.h)));
}
void ObjetoPG::draw(){
	if (visible && !dest){
		juego->getTextura(textura)->draw(juego->getRender(), rect);
	}
}