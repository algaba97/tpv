
#include "GlobosPG.h"

#include <iostream>
#include<stdlib.h>
#include "SDL.h"
#include <ctime>


using namespace std;

GlobosPG::GlobosPG(JuegoPG*jogo, int px, int py, int tipo) :ObjetoPG(jogo,px,py)
{
	tam = TAMANYO;
	if (tipo == 0)
	textura = TGlobo1;
	else textura = TGlobo2;
	rect.h = juego->getTextura(textura)->getx() / 9;
	rect.w = juego->getTextura(textura)->gety() / 9;

	
}
GlobosPG::~GlobosPG()
{
}
//Disminuye el tamaño(Hasta que es 0 y se elimina el globo)
void GlobosPG::update(){

	if (rand() % 100 < PDES){
		if (tam - DT > 0){
			puntos += AP;
			tam -= DT;
			rect.w = (rect.w / TAMANYO)*tam;// CAMBIA EL TAMAÑO DEL GLOBO
			rect.x += (rect.w / tam)*DT;//Para que cambiando el tamaño el globo siga centrado
		}
		else{
			juego->newBaja(this);
			dest = true;
		}
	}
	if (rand() % 100 < PVIS) visible = true; else visible = false;
}
//Metodo que mira si el goblo tiene una poscion con pmx pmy
bool GlobosPG::onClick(){
	juego->getMousePos(x,y);
	if (!dest && visible &&dentro(x, y)){
		cout << "Clikando";
		damePuntos();
		juego->newPuntos(this);
		juego->newBaja(this);
		return true;
	}
	else return false;
	
}
