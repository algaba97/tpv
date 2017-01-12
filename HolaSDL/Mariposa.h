
#include <iostream>
#include "ObjetoPG.h"

#ifndef MARIPOSA_H
#define MARIPOSA_H


class Mariposa : public ObjetoPG
{
public:
	Mariposa(JuegoPG*jogo, int px, int py);
	~Mariposa();
	 void update();
	 bool onClick();
	 void draw();

	
private:
	int numClicks = 0;
	
	int posicion = 1;
	SDL_Rect cacho;
};
#endif
