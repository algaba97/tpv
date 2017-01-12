#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <SDL.h>
using namespace std;
class Error
{
protected:
	string mensaje;
public:
	Error(string m)  {
		mensaje = m;
		
	}
	string const Mensaje(){
		return mensaje;
	}
	~Error();
	

};
#endif
