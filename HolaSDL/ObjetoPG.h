#ifndef OBJETOPG_H
#define OBJETOPG_H

#include "SDL.h"
#include "ObjetoJuego.h"
#include "JuegoPG.h"


class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG(JuegoPG*jogo, int px, int py);
	virtual ~ObjetoPG();
	bool dentro(int x, int y)const;
    virtual int damePuntos()const{ return puntos; };
	void draw();
	bool destruido()const { return dest; };
     void destruir() { dest = true; };
	virtual bool esVisible() const{ return visible; };
         virtual void visibilizar(){ visible = true; };
	 
private:
	
	
protected:
	int x, y;
	bool dest;
	bool visible;
	Texturas_t textura;
	JuegoPG* juego;
	SDL_Rect rect;
	int puntos;
	
};

#endif