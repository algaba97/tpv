#ifndef ESTADOPG_H
#define ESTADOPG_H
#include "EstadoJuego.h"
#include "JuegoPG.h"
#include "ObjetoJuego.h"
#include <vector>
class EstadoPG : public EstadoJuego
{
public:
	EstadoPG();
	void update(){ for (int i = 0; i < objetos.size(); i++)objetos[i]->update(); }
	void draw(){ for (int i = 0; i < objetos.size(); i++)objetos[i]->draw(); }
	void onClick();
	virtual ~EstadoPG();
protected:
	JuegoPG* juego;
	vector<ObjetoJuego*> Objetos;
};
#endif
