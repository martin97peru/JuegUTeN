#include <iostream>

#define CODS 100
#define LINEAS 20
#define JUGKC 5
#include "Declaraciones.h"

using namespace std;

struct Codigo {
	string lineas[LINEAS];
	int errores[LINEAS];
	int cantLineas;
	int cantErrores;
};
void instruccionesKC();
void jugarKC(int nequipo, int nusuario,equipo principal[]);
bool cargarCodigos(Codigo codigos[CODS], int & cant);
int menuJuegoKC(int menu);
void verEvolucionKC(int nequipo, int nusuario,equipo principal[]);
void KingCoder(int nequipo,int nusuario,equipo principal[]);
void inicializar(Codigo codigos[]);
