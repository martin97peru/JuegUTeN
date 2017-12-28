#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "simon.h"

using namespace std;

void simon(int nequipo,int nusuario,equipo principal[]) {
	system("CLS");
	char teclas[4];
	int menu=0;
	
	while (menu!=9){
		
		menu = menuJuego(menu);	
		while(menu!=1 && menu!=2 && menu!=3 && menu!=9){
			cout<< endl << "Error! Ingrese una opcion valida." << endl<<endl;
			system("pause");
			system("cls");
			menu = menuJuego(menu);
		}
		system("CLS");
		if(menu == 1){
			verInstrucciones();
			system("PAUSE");
			system("CLS");
		}
		else 
			if(menu == 2){
			cout << "Ingrese las teclas con las que desea jugar." << endl;
			
			seleccionarTeclas(teclas);
			
			while(!validarTeclas(teclas)){
				seleccionarTeclas(teclas);
			}
			
			cout  << "Teclas elegidas: " << endl;
			
			mostrarTeclas(teclas);
			
			system("pause");
			
			jugarSM(teclas, nequipo, nusuario, principal);	
		}
			else
				if(menu == 3){
			Evolucion(nequipo, nusuario,principal);
		}
		system("CLS");
	}
	
}

int menuJuego(int menu){
	cout << " Ingrese una opcion: " << endl;
	cout << endl;
	cout << " 1 - Ver Instrucciones " << endl;
	cout << " 2 - Jugar! " << endl;
	cout << " 3 - Ver evolucion " << endl;
	cout << " 9 - Salir " << endl;
	cout << endl << "Opcion: " ;
	cin >> menu;
	
	return menu;	
	
}
void seleccionarTeclas (char teclas[]){
	cout << endl << "Ingrese la tecla superior izquierda: " ;
	cin >> teclas[0];
	
	cout << endl << "Ingrese la tecla superior derecha: " ;
	cin >> teclas[1];
	
	cout << endl<< "Ingrese la tecla inferior izquierda: " ;
	cin >> teclas[2];
	
	cout<< endl << "Ingrese la tecla inferior derecha: " ;
	cin >> teclas[3];
}

bool validarTeclas (char teclas[]){
	int i,aux=0;
	
	for (i=0; i<4; i++){
		if(teclas[i]>=97 && teclas[i] <= 122){
			teclas[i] = teclas[i]-32; 
		}
	}
	
	for (i=0; i<4; i++){
		if(teclas[i]==teclas[i+1] or teclas[i]==teclas[i+2] or teclas[i]==teclas[i+3]){
			aux++;
		}
	}
	if(aux>0){
		cout << endl  << "ERROR! Ingrese 4 teclas diferentes." << endl;
		
		system("PAUSE");
		
		system("CLS");
		
		return false;
	}else{
		cout<<"Las teclas elegidas son correctas"<<endl;
		return true;
	}
}

void mostrarTeclas (char teclas[]){
	system("CLS");
	cout << "Teclas elegidas: " << endl;
	
	cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
	cout<<		"|         |    |  |         |"<<endl;
	cout<<		"|         |    |  |         |"<<endl;
	cout<<		"|    "<<teclas[0]<<"    |    |  |    "<<teclas[1]<<"    |"<< endl;
	cout<<		"|         |    |  |         |"<< endl;
	cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
	cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
	cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
	cout<<		"|         |    |  |         |"<<endl;
	cout<<		"|         |    |  |         |"<<endl;
	cout<<		"|    "<<teclas[2]<<"    |    |  |    "<<teclas[3]<<"    |"<< endl;
	cout<<		"|         |    |  |         |"<< endl;
	cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
	cout << endl;
}

void jugarSM (char teclas[],int nequipo,int nusuario,equipo principal[]){
	int opcion[30],i=0,j=0,puntaje = 0, puntajejugada=0,mayor;
	char respuesta,correcto[30];
	string nivel;
	system("CLS");
	
	srand(time(NULL));
	
	for(i=0; i<30; i++ ){
		opcion[i] = rand()%4;
		
	}
	
	i=0;
	
	
	while (i<30) {
		
		for(j=0; j<=i;j++){
			switch (opcion[j]){
			case 0: {
				cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|    "<<teclas[0]<<"    |    |  |         |"<< endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
				cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
				cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
				correcto[j] = teclas[0];
				break;
			}
			case 1:{
				cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |    "<<teclas[1]<<"    |"<< endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
				cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
				cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<<endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|         |    |  |         |"<< endl;
				cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
				correcto[j] = teclas[1];
				break;
			}
			case 2:{
					cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
					cout<<		"|         |    |  |         |"<<endl;
					cout<<		"|         |    |  |         |"<<endl;
					cout<<		"|         |    |  |         |"<< endl;
					cout<<		"|         |    |  |         |"<< endl;
					cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
					cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
					cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
					cout<<		"|         |    |  |         |"<<endl;
					cout<<		"|         |    |  |         |"<<endl;
					cout<<		"|    "<<teclas[2]<<"    |    |  |         |"<< endl;
					cout<<		"|         |    |  |         |"<< endl;
					cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
					
					correcto[j] = teclas[2];
					break;
				}
			case 3:{
						
						cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
						cout<<		"|         |    |  |         |"<<endl;
						cout<<		"|         |    |  |         |"<<endl;
						cout<<		"|         |    |  |         |"<< endl;
						cout<<		"|         |    |  |         |"<< endl;
						cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
						cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
						cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
						cout<<		"|         |    |  |         |"<<endl;
						cout<<		"|         |    |  |         |"<<endl;
						cout<<		"|         |    |  |    "<<teclas[3]<<"    |"<< endl;
						cout<<		"|         |    |  |         |"<< endl;
						cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
						
						correcto[j] = teclas[3];	
						break;}
						
			}
			Sleep(1000);
			system("CLS");
			Sleep(200);
			
		}
		
		cout <<     " _ _ _ _ _         _ _ _ _ _"<< endl;					
		cout<<		"|         |    |  |         |"<<endl;
		cout<<		"|         |    |  |         |"<<endl;
		cout<<		"|    "<<teclas[0]<<"    |    |  |    "<<teclas[1]<<"    |"<< endl;
		cout<<		"|         |    |  |         |"<< endl;
		cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
		cout<<      "_ _ _ _ _ _ _ _|_ _ _ _ _ _ _  " << endl;		
		cout <<     " _ _ _ _ _     |   _ _ _ _ _"<< endl;
		cout<<		"|         |    |  |         |"<<endl;
		cout<<		"|         |    |  |         |"<<endl;
		cout<<		"|    "<<teclas[2]<<"    |    |  |    "<<teclas[3]<<"    |"<< endl;
		cout<<		"|         |    |  |         |"<< endl;
		cout<<		"|_ _ _ _ _|    |  |_ _ _ _ _|" << endl;
		cout << endl;
		
		
		
		cout<<endl << "Simon dice: ";
		for(j=0;j<i+1;j++){
			cout << correcto[j]<<" - ";
		}
		cout << endl <<endl;
		system("pause");
		system("CLS");
		j=0;
		
		do{
			
			cout << "Ingrese respuesta " << j<< ": " ;
			cin >> respuesta;
			validarTeclas2(respuesta);
			if(respuesta != correcto[j]){
				
				i = 30;
				j = i;
			}
			else{
				puntaje = i;
			}
			
			j++;
			
		}while(j <= i && respuesta == correcto[j-1]);
		
		
		i++;
		
		system ("CLS");
	}
	system ("CLS");
	
	puntajejugada = (puntaje*(puntaje+1))/2;
	
	if (puntajejugada == 0){
		cout <<endl<<"   ***************" << endl;
		cout << "  *** PERDISTE! ***" << endl;
		cout << "   ***************" << endl;
	}
	else{
		
		cout<<endl <<"    FELICITACIONES! Tu puntaje fue: " <<  (puntajejugada) << endl;
		
	}
	
	
	if(puntajejugada <= 15){
		nivel = "Principiante";
	}
	else
		if(puntajejugada >15 && puntajejugada <= 55){
		nivel = "Discipulo" ;
	}
		else if (puntajejugada > 55 && puntajejugada <= 210){
		nivel = "Experto" ;
	}
		else if(puntajejugada>210){
		nivel = "Erudito" ;
	}
	
	
	cout << endl <<"    Nivel alcanzado en esta partida: " << nivel << endl ; 
	
	cout << endl << "/////////////////////////////////////" << endl;
	cout << endl << " ---- RESPUESTA CORRECTA ----"<< endl << endl;
	
	for(i=0; i<=puntaje; i++){
		cout <<"- " << correcto[i] << " - " ; 
	}
	
	mayor=principal[nequipo].jugadores[nusuario].mejoresjugadas[1].maxpuntaje;
	if(puntajejugada>mayor){
		principal[nequipo].jugadores[nusuario].mejoresjugadas[1].maxpuntaje=puntajejugada;
	}
	
	principal[nequipo].jugadores[nusuario].mejoresjugadas[1].cantjugadas++;
	
	system("PAUSE");
	
	
	
	
	
	calcularl1(nequipo,1,principal,mayor);
	
	
	
	
}

void validarTeclas2 (char &teclas){
	if(teclas>=97 && teclas <= 122){
		teclas = teclas-32; 
	}
}

void verInstrucciones(void){
	cout << " ---- SIMON ----> Instrucciones ---- " <<  endl <<endl;
	cout << " El juego consiste en un tablero dividido en cuatro cuadrados y cada uno posee un caracter elegido"<<endl<<"por el usuario."<< endl;
	cout << " Durante el juego, se muestra aleatoriamente un secuencia de los caracteres y el usuario debe"<<endl<<"recordar el orden en que estos aparecieron."<< endl;
	cout << " Si el usuario acierta la secuencia, se muestra la misma pero con un caracter agregado"<<endl<<"aleatoriamente." <<endl;
	cout << " El juego finaliza si el usuario no acierta la secuencia o si acierta una secuencia de 30"<<endl<<"caracteres." <<endl;
	cout << endl << "  PUNTUACION." << endl;
	cout <<" Por cada secuencia acertada al usuario se le acumula la respectiva cantidad de caracteres." << endl;
	cout << " Es decir, en la primer secuencia suma un punto; en la segunda, dos puntos; y asi sucesivamente. "<< endl<<endl;
	
}

void Evolucion(int nequipo, int nusuario,equipo principal[]){
	int puntajejugada = principal[nequipo].jugadores[nusuario].mejoresjugadas[1].maxpuntaje;
	
	cout << "Cantidad de veces jugadas: " << principal[nequipo].jugadores[nusuario].mejoresjugadas[1].cantjugadas << endl;
	cout << endl << "Puntaje maximo: " <<principal[nequipo].jugadores[nusuario].mejoresjugadas[1].maxpuntaje << endl;
	cout << endl;
	if(puntajejugada <= 15){
		cout << "Nivel: Principiante" << endl;
	}
	else
		if(puntajejugada >15 && puntajejugada <= 55){
		cout <<  "Nivel: Discipulo" << endl ;
	}
		else if (puntajejugada > 55 && puntajejugada <= 210){
		cout <<  "Nivel: Experto"<<endl;
	}
		else if(puntajejugada>210){
		cout << "Nivel: Erudito"<< endl ;
	}
	system("PAUSE");
}
