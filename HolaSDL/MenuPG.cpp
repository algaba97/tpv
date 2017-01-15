#include "MenuPG.h"

#include "Boton.h"
#include "PlayPG.h"


MenuPG::MenuPG(JuegoPG*Juego):EstadoPG(Juego)
{
	Objetos.push_back(new Boton(Jugar, juego,juego->getAncho() / 2, juego->getAlto() / 2 - 50 ));
	Objetos.push_back(new Boton(Salir, juego ,juego->getAncho() / 2, juego->getAlto() / 2 + 50));
	
}


MenuPG::~MenuPG()
{
}
