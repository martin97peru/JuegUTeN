#include <iostream>
#include "Declaraciones.h"
using namespace std;
//gg izi
void calcularl1(int nequipo,int juego,equipo principal[],int mayor){
	int puntaje;
	if(juego==0){
		puntaje=23;
	}else{
		if(juego==1){
			puntaje=55;
		}else{
			if(juego==2){
				puntaje=50;
			}
		}
	}
	if(mayor<puntaje){
		int contador=0;
		for(int i=0;i<principal[nequipo].cantmiembros;i++){
			if(principal[nequipo].jugadores[i].mejoresjugadas[juego].maxpuntaje>puntaje){
				contador++;
			}
		}
		if(contador==principal[nequipo].cantmiembros){
			principal[nequipo].medallas[juego]++;
		}
	}
}
