#include "PlayPG.h"
#include "ObjetoPG.h"
#include <iostream>
using namespace std;

PlayPG::PlayPG()
{
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
