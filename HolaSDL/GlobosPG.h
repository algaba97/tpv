

#include <iostream>
#include "ObjetoPG.h"
#ifndef GLOBOSPG_H
#define GLOBOSPG_H

using namespace std;
class GlobosPG : public ObjetoPG
{
public:            
	
	GlobosPG(PlayPG*est,JuegoPG*jogo, int px, int py, int tipo);

	~GlobosPG();
	virtual void update();
	virtual bool onClick();
	
protected:


	static const int PVIS = 70;
	static const int PDES = 30;
	static const int DT = 5;
	static const int AP = 5;
	static const int TAMANYO = 20;

	
	int tam;
private:
	PlayPG*estado;
};
#endif