#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "Simon.h"
#include "Teklader.h"
#include "kingcoder.h"

using namespace std;

void registro(equipo principal[]);
void sesion(equipo principal[]);
int menuprincipal();
bool fecha(int d,int m,int a);
int asignacionequipo(int d,int m);
string contra(int team, equipo principal[]);
bool valida (string clave, int team, equipo principal[]);
int cualequipo(string t);
string pasaraminuscula(string x);
int cualkey(string k,int eq,equipo principal[]);
void menudejuegos(int nequipo,int nusuario,equipo principal[]);
void calcularinsigniasmenu(int nequipo,equipo principal[]);
void insigniasequipo(int nequipo,equipo principal[]);
void insigniastotal(equipo principal[]);
bool calculoplata(int nequipo,equipo principal[]);
void escribirArchivo (equipo principal[]);
void leerArchivo (equipo principal[]);
void escribirinsignias(equipo principal[]);
void leerinsignias(equipo principal[]);
