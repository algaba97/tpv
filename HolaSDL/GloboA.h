#include <iostream>
#include "GlobosPG.h"
#ifndef GLOBOSA_H
#define GLOBOSA_H
class GloboA : public GlobosPG
{
public:

	GloboA(JuegoPG*jogo, int px, int py, int tipo);
	~GloboA();
	virtual void update();

};
#endif
