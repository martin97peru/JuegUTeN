#ifndef TEKLADER_H
#define TEKLADER_H

#include <iostream>
#include "Declaraciones.h"
#include "general.h"
using namespace std;

void teklader (int nequipo,int nusuario, equipo principal[]);
int menuJuegoTK (int menu);
void verInstruccionesTK (void);
void EvolucionTK (int nequipo, int nusuario, equipo principal[]);
void jugarTK (int nequipo,int nusuario, equipo principal[]);
void tecladoTK ();


#endif
