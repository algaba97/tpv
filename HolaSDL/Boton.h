#ifndef BOTON_H
#define BOTON_H
#include "ObjetoPG.h"
class Boton : public ObjetoPG
{
public:
	// typedef void (*myfunc)(); compila como  myfunc f;      // compile equally as  void (*f)();
	typedef void CallBack_t(JuegoPG* jg);
	Boton(CallBack_t* callback,JuegoPG*jogo, int px, int py);
	~Boton();
	virtual bool onClick();
	virtual void update(){}//está por hacer}
	
protected: 
	CallBack_t * cb;
};
#endif
