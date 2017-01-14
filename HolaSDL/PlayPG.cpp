#include "PlayPG.h"
#include "ObjetoPG.h"
#include <iostream>
#include "ObjetoJuego.h"
#include "GlobosPG.h"
using namespace std;

PlayPG::PlayPG(){

int a, b, c;
for (int i = 0; i < globos; i++){
	c = i % 2;
	a = rand() % 770;
	b = rand() % 770;
	if (c == 1)Objetos.push_back(new GloboA(this, a, b, 1));
	else Objetos.push_back(new GlobosPG(this, a, b, 0));
}
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Mariposa(this, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Mariposa(this, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Premio(this, a, b));
a = rand() % 770;
b = rand() % 770;
Objetos.push_back(new Premio(this, a, b));
}


PlayPG::~PlayPG()
{
}

void PlayPG::update(){
	EstadoPG::update();
	for (int i = 0; i < globos; i++){
		if (!dynamic_cast<ObjetoPG*>(objetos[i])->destruido())fin = false;
	}

	if (fin){
		//juego->changeState(EstadoJuego* newSt);
		//llamar al cambio de estado
	}
		
}
