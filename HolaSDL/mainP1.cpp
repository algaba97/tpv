//Jorge Algaba


#pragma once
#include "SDL.h"  // Para utilizar SDL
#include <iostream>  // la consola: cin / cout
#include "JuegoPG.h"
#include "Error.h"


using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


int main(int argc, char* args[]) {  // SDL require esta cabecera 
	cout << "Hola";
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	JuegoPG juego;

	try{ juego.run(); }
	catch (Error & e){ e.Mensaje(); }

	return 0;
}
