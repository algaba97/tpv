#ifndef PLAYPG_H
#define PLAYPG_H
#include "EstadoPG.h"
class PlayPG : public EstadoPG
{
public:
	PlayPG(JuegoPG*Juego);
	~PlayPG();
	void update();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po); 
	void newPremio();
	void initObjetos();
private:
	bool fin;
	int contador;
	int globos = 4;
};
#endif
