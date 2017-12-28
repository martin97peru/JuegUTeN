#ifndef SIMON_H
#define SIMON_H

#include <iostream>
#include "Declaraciones.h"

using namespace std;

int menuJuego(int menu);
void verInstrucciones(void);
void Evolucion (int nequipo, int nusuario,equipo principal[]);
void seleccionarTeclas (char teclas[]);
bool validarTeclas (char teclas[]);
void validarTeclas2 (char &teclas);
void mostrarTeclas (char teclas[]);
void jugarSM (char letras[],int nequipo,int nusuario,equipo principal[]);
void simon(int nequipo,int nusuario,equipo principal[]);


#endif
