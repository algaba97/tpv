#include "PlayPG.h"
#include "ObjetoPG.h"
#include <iostream>
#include "ObjetoJuego.h"
#include "EstadoJuego.h"
#include "GloboA.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "Mariposa.h"
using namespace std;

PlayPG::PlayPG(JuegoPG*Juego): EstadoPG(Juego){
	initObjetos();
}
void PlayPG::initObjetos(){
	int a, b, c;
	for (int i = 0; i < globos; i++){
		
		a = rand() % 770;
		b = rand() % 770;
		
	 Objetos.push_back(new GlobosPG(this, juego, a, b, 0));
	}
	a = rand() % 770;
	b = rand() % 770;
	Objetos.push_back(new Mariposa(this, juego, a, b));
	a = rand() % 770;
	b = rand() % 770;
	Objetos.push_back(new Mariposa(this, juego, a, b));
	a = rand() % 770;
	b = rand() % 770;
	Objetos.push_back(new Premio(this, juego, a, b));
	a = rand() % 770;
	b = rand() % 770;
	Objetos.push_back(new Premio(this, juego, a, b));
}

PlayPG::~PlayPG()
{
}

void PlayPG::update(){

		
}
void PlayPG::newBaja(ObjetoJuego* po){
	if (dynamic_cast<GlobosPG*>(po) != nullptr){
		dynamic_cast<ObjetoPG*>(po)->destruir();
		cout << "baja";
	}

}
void PlayPG::newPuntos(ObjetoJuego* po){
		contador += static_cast<ObjetoPG*>(po)->damePuntos();
}
void PlayPG::newPremio(){
	int a = rand() % 770;
	int b = rand() % 770;
	//Objetos[Objetos.size() - 1]->visible = true;//siempre es el ultimo elemento y no se borra nunca
	int i = 1;
	bool fin = false;
	while (!fin){
		if (!dynamic_cast<ObjetoPG*>(Objetos[Objetos.size() - i])->esVisible()){

			fin = true;
			dynamic_cast<ObjetoPG*>(Objetos[Objetos.size() - i])->visibilizar();
		}
		i++;
	}

}
