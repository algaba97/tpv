#ifndef PLAYPG_H
#define PLAYPG_H
#include "EstadoPG.h"
class PlayPG : public EstadoPG
{
public:
	PlayPG();
	~PlayPG();
	void update();
private:
	bool fin;
	int contador;
	int globos = 4;
};
#endif
