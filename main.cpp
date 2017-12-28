#include <iostream>
#include <windows.h>
#include <conio.h>
#include "libjueguten.h"
#include "general.h"
#include "logo.h"
#include <fstream>
using namespace std;

equipo principal[13];


void marco () {
	for (int i=1; i<119; i++) {
		gotoxy(i,1); printf("%c",205);
		gotoxy(i,38); printf("%c",205);
	}
	for (int i=1; i<38; i++) {
		gotoxy(1,i); printf("%c",186);
		gotoxy(118,i); printf("%c",186);
	}
	gotoxy(1,1); printf("%c",201);
	gotoxy(1,38); printf("%c",200);
	gotoxy(118,1); printf("%c",187);
	gotoxy(118,38); printf("%c",188);
}


int main(){
	leerArchivo(principal);
	leerinsignias(principal);
	
	principal[0].nombre="ZORRO";
	
	principal[1].nombre="SERPIENTE";
	
	principal[2].nombre="ARDILLA";
	
	principal[3].nombre="TORTUGA";
	
	principal[4].nombre="MURCIELAGO";
	
	principal[5].nombre="ALACRAN";
	
	principal[6].nombre="VENADO";
	
	principal[7].nombre="LECHUZA";
	
	principal[8].nombre="GALLO";
	
	principal[9].nombre="LAGARTO";
	
	principal[10].nombre="GORILA";
	
	principal[11].nombre="HALCON";
	
	principal[12].nombre="JAGUAR";
	
	system("mode con: cols=120 lines=40");
	system("color 71");
	marco();
	pantalla_inicial();
	system("color 71");
	
	int auxiliar=menuprincipal();
	system("CLS");
	while(auxiliar!=9){
		switch(auxiliar){
		case 1: registro(principal); break;
		case 2: sesion(principal); break;
		}
		auxiliar=menuprincipal();
	}

	cout<<endl<<"Gracias por jugar JuegUTeN, nos vemos! :D"<<endl;
	escribirArchivo(principal);
	escribirinsignias(principal);
	
	return 0;
}

void escribirArchivo (equipo principal[]){
	ofstream f;
	int i;

	f.open("Equipos.dat");
	for(i=0; i < 13;i++){ 
		//f << principal[i].nombre << endl;
		f << principal[i].cantmiembros<< endl;
			for(int j=0; j < 5; j++){
				for(int k=0;k<10; k++){
					f<<principal[i].jugadores[j].clave[k];
				}
				f << endl;
				for(int m=0; m<3;m++){
					f<<principal[i].jugadores[j].mejoresjugadas[m].maxpuntaje<<endl;
					f<<principal[i].jugadores[j].mejoresjugadas[m].cantjugadas<<endl;
				}
			}
	}
	f.close();
}
void leerArchivo(equipo principal[]){
	ifstream g;
	int i;
	g.open("Equipos.dat");
	for(i=0; i < 13;i++){
		//getline(g, principal[i].nombre ,'\n');
		g>> principal[i].cantmiembros;
		for(int j=0; j < 5; j++){
			for(int k=0;k<10; k++){
				g>>principal[i].jugadores[j].clave[k];
			}
			for(int m=0; m<3;m++){
				g>>principal[i].jugadores[j].mejoresjugadas[m].maxpuntaje;
				g>>principal[i].jugadores[j].mejoresjugadas[m].cantjugadas;
			}
	}
	}
	g.close();
}
void escribirinsignias(equipo principal[]){
	ofstream salida;
	salida.open("Insignias.dat");
	for(int i=0; i < 13;i++){
		for(int j=0;j<3;j++){
			salida<<principal[i].medallas[j]<<endl;
		}
	}
	salida.close();
}
void leerinsignias(equipo principal[]){
	ifstream entrada;
	entrada.open("Insignias.dat");
	for(int i=0; i < 13;i++){
		for(int j=0;j<3;j++){
			entrada>>principal[i].medallas[j];
		}
	}
	entrada.close();
}
