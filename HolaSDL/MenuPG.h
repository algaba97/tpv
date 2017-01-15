#ifndef MENUPG_H
#define MENUPG_H
#include "EstadoPG.h"
#include"PlayPG.h"
class MenuPG : public EstadoPG
{
public:
	MenuPG(JuegoPG *Juego);
	~MenuPG();
private:
	    static void Salir(JuegoPG*juego) { juego->setSalir(); }
		static void Jugar(JuegoPG*juego) { juego->changeState(new PlayPG(juego)); }
};
#endif
