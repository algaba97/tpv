#include "PlayPG.h"
#include "ObjetoPG.h"
#include <iostream>
#include "ObjetoJuego.h"
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
	EstadoPG::update();
	for (int i = 0; i < globos; i++){
		if (!dynamic_cast<ObjetoPG*>(Objetos[i])->destruido())fin = false;
	}

	if (fin){
		//juego->changeState(EstadoJuego* newSt);
		//llamar al cambio de estado
	}
		
}
