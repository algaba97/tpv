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

int a, b, c;
for (int i = 0; i < globos; i++){
	c = i % 2;
	a = rand() % 770;
	b = rand() % 770;
	if (c == 1)Objetos.push_back(new GloboA(juego, a, b, 1));
	else Objetos.push_back(new GlobosPG(juego, a, b, 0));
}
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Mariposa(juego, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Mariposa(juego, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Premio(juego, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Premio(juego, a, b));
}


PlayPG::~PlayPG()
{
}

void PlayPG::update(){
	juego->update();
	for (int i = 0; i < globos; i++){
		if (!dynamic_cast<ObjetoPG*>(Objetos[i])->destruido())fin = false;
	}

	if (fin){
		//juego->changeState(GAM);
		//llamar al cambio de estado
	}
		
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
