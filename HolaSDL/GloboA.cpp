#include "GloboA.h"

#include <iostream>
#include<stdlib.h>
#include "SDL.h"
#include <ctime>


using namespace std;

GloboA::GloboA(JuegoPG*jogo, int px, int py, int tipo) :GlobosPG(jogo,px,py,tipo)
{
	
}


GloboA::~GloboA()
{
}
//Disminuye el tamaño(Hasta que es 0 y se elimina el globo)
void GloboA::update(){
	GlobosPG::update();
	visible = true;
	if (rect.y < 20){
		if (0 >= puntos - 2*AP) puntos -= 2*AP;
	}
	else {
		puntos += AP;
		rect.y -= 50;
	}
}
