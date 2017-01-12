//Jorge Algaba


#pragma once
#include "SDL.h"  // Para utilizar SDL
#include <iostream>  // la consola: cin / cout
#include "JuegoPG.h"


using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


int main(int argc, char* args[]) {  // SDL require esta cabecera 
	cout << "Hola";
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	JuegoPG juego;

	juego.run();
	return 0;
}
