#include <iostream>
#include "GlobosPG.h"
#ifndef GLOBOSA_H
#define GLOBOSA_H
class GloboA : public GlobosPG
{
public:

	GloboA(PlayPG*est,JuegoPG*jogo, int px, int py, int tipo);
	~GloboA();
	virtual void update();

};
#endif
