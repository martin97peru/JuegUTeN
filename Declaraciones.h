#ifndef DECLARACIONES_H
#define DECLARACIONES_H

#include <iostream>

using namespace std;

struct juego{
	char nombre[10];
	int maxpuntaje;
	int cantjugadas;
};
struct miembro{
	char clave[10];
	juego mejoresjugadas[3];
};
struct equipo{
	string nombre;
	int cantmiembros;
	miembro jugadores[5];
	int medallas[3];
};

void calcularl1(int nequipo,int juego,equipo principal[],int mayor);

#endif
