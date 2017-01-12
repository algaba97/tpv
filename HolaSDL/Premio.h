#ifndef PREMIO_H
#define PREMIO_H
#include <iostream>
#include "ObjetoPG.h"


class Premio : public ObjetoPG
{
public:
	Premio(JuegoPG*jogo, int px, int py);
	~Premio();
	void update();
	bool onClick();
	void reinicio();
	
private:
	int ticks;
};
#endif

