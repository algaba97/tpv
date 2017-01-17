#ifndef ESTADOPG_H
#define ESTADOPG_H
#include "EstadoJuego.h"
#include "JuegoPG.h"
#include "ObjetoJuego.h"
#include <vector>
class EstadoPG : public EstadoJuego
{
public:
	EstadoPG(JuegoPG * juego);
	void update(){ for (int i = 0; i < Objetos.size(); i++)Objetos[i]->update(); }
	void draw();
	void onClick();
	virtual ~EstadoPG();
protected:
	JuegoPG* juego;
	vector<ObjetoJuego*> Objetos;
};
#endif
