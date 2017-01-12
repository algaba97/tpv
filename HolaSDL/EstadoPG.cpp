#include "EstadoPG.h"


EstadoPG::EstadoPG()
{
}


EstadoPG::~EstadoPG()
{
}
 void EstadoPG::onClick(){
	 bool pinchado = false;
	 for (int i = 0; i < objetos.size() && !pinchado; i++)
		 if (objetos[i]->onClick())pinchado = true;
 
}