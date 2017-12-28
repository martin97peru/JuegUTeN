#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include "Teklader.h"

using namespace std;

void teklader (int nequipo,int nusuario,equipo principal[]) {
	system("CLS");
	int menu=0;
	
	while (menu!=9){
		
		menu = menuJuegoTK(menu);	
		while(menu!=1 && menu!=2 && menu!=3 && menu!=9){
			cout<< endl << "Error! Ingrese una opcion valida." << endl<<endl;
			system("pause");
			system("cls");
			menu = menuJuegoTK(menu);
		}
		system("CLS");
		if(menu == 1){
			verInstruccionesTK ();
			system("PAUSE");
			system("CLS");
		}
		else 
			if(menu == 2){
			jugarTK (nequipo, nusuario, principal);	
		}
			else
				if(menu == 3){
				EvolucionTK (nequipo, nusuario,principal);
			}
		system("CLS");
	}
	
}

int menuJuegoTK (int menu){
	cout << " Ingrese una opcion: " << endl << endl;
	cout << " 1 - Ver Instrucciones " << endl;
	cout << " 2 - Jugar! " << endl;
	cout << " 3 - Ver evolucion " << endl;
	cout << " 9 - Salir " << endl << endl;
	cout << "Opcion: " ;
	cin >> menu;
	
	return menu;	
	
}

char teclado [20][113] = {
	"1hhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhhthhhhhhh2        ",
		"v      v       v       v       v       v       v       v       v       v       v       v       v       v        ",
		"v      v       v       v       v       v       v       v       v       v       v       v       v       v        ",
		"v      v       v       v       v       v       v       v       v       v       v       v       v       v        ",
		"3hhhhhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhh2    ",
		"           v       v       v       v       v       v       v       v       v       v       v       v       v    ",
		"           v       v       v       v       v       v       v       v       v       v       v       v       v    ",
		"           v       v       v       v       v       v       v       v       v       v       v       v       v    ",
		"           3hhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhh2",
		"               v       v       v       v       v       v       v       v       v       v       v       v       v",
		"               v       v       v       v       v       v       v       v       v       v       v       v       v",
		"               v       v       v       v       v       v       v       v       v       v       v       v       v",
		"               3hhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhthhhihhhhhhh4",
		"                   v       v       v       v       v       v       v       v       v       v       v            ",
		"                   v       v       v       v       v       v       v       v       v       v       v            ",
		"                   v       v       v       v       v       v       v       v       v       v       v            ",
		"                   3hhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhhihhhhhhh4            ",
};


void tecladoTK () {
	gotoxy(50,3); cout<<"TEKLADER";
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 113 ; i++) {
			switch (teclado [j][i]) {
			case 'h': gotoxy(i+4,j+6); printf("%c",196); break;
			case 'v': gotoxy(i+4,j+6); printf("%c",179); break;
			case '1': gotoxy(i+4,j+6); printf("%c",218); break;
			case '2': gotoxy(i+4,j+6); printf("%c",191); break;
			case '3': gotoxy(i+4,j+6); printf("%c",192); break;
			case '4': gotoxy(i+4,j+6); printf("%c",217); break;
			case 't': gotoxy(i+4,j+6); printf("%c",194); break;
			case 'i': gotoxy(i+4,j+6); printf("%c",193); break;
			case 'c': gotoxy(i+4,j+6); printf("%c",197); break;
			default: gotoxy(i+4,j+6); printf(" ");
			}
		}
	}
	gotoxy(23,16); cout<<"A";
	gotoxy(31,16); cout<<"S";
	gotoxy(39,16); cout<<"D"; 
	gotoxy(47,16); cout<<"F";
	gotoxy(71,16); cout<<"J";
	gotoxy(79,16); cout<<"K"; 
	gotoxy(87,16); cout<<"L";
	gotoxy(95,16); cout<<(char)165;
	gotoxy(24,26); cout<<"Utilice A,S,D,F con la mano izquierda y J,K,L,"<<(char)165<<" con la mano derecha";
	gotoxy(35,30); cout<<"NO OLVIDE TENER EL BLOQUEO DE MAYUSCULAS ACTIVADO";
	gotoxy(40,34); cout<<"Preione una tecla para comenzar . . .";
	system ("pause>null");
	gotoxy(23,16); cout<<" ";
	gotoxy(31,16); cout<<" ";
	gotoxy(39,16); cout<<" "; 
	gotoxy(47,16); cout<<" ";
	gotoxy(71,16); cout<<" ";
	gotoxy(79,16); cout<<" "; 
	gotoxy(87,16); cout<<" ";
	gotoxy(95,16); cout<<" ";
	gotoxy(24,26); cout<<"                                                                   ";
	gotoxy(35,30); cout<<"                                                 ";
	gotoxy(40,34); cout<<"                                     ";
}

void jugarTK (int nequipo,int nusuario,equipo principal[]){
	tecladoTK();
	int error=0, cantidad=0, puntaje=0, posCaracter, TL=47, mayor;
	string nivel;
	char C='^', ingresar, vector[]={'|','1','2','3','4','5','6','7','8','9','0',(char)39,(char)168,'Q','W','E','R','T','Y','U','I','O','P',(char)239,'+','A','S','D','F','G','H','J','K','L',(char)165,'{','}','Z','X','C','V','B','N','M',',','.','-'};
	while (error<5 && cantidad<47) {
		
		int i=0;
		srand (time(NULL));
		C = vector[rand()%TL];
		while (i<TL){
			if (C==vector[i]){
				posCaracter=i;
			}
			i++;
		}
		for (int j=posCaracter; j<TL-1; j++ ) {
			vector[j]=vector[j+1];
		}
		TL--;
		
		switch (C) {
		case '|': gotoxy(7,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 1      "; gotoxy(7,8); break;
		case '1': gotoxy(15,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 2      "; gotoxy(15,8); break;
		case '2': gotoxy(23,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 3      "; gotoxy(23,8); break;
		case '3': gotoxy(31,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 4      "; gotoxy(31,8); break;
		case '4': gotoxy(39,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 5      "; gotoxy(39,8); break;
		case '5': gotoxy(47,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 6      "; gotoxy(47,8); break;
		case '6': gotoxy(55,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 7      "; gotoxy(55,8); break;
		case '7': gotoxy(63,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 8      "; gotoxy(63,8); break;
		case '8': gotoxy(71,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 9      "; gotoxy(71,8); break;
		case '9': gotoxy(79,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 10     "; gotoxy(79,8); break;
		case '0': gotoxy(87,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 11     "; gotoxy(87,8); break;
		case (char)39: gotoxy(95,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 12     "; gotoxy(95,8); break;
		case (char)168: gotoxy(103,8); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 1, columna 13     "; gotoxy(103,8); break;
		case 'Q': gotoxy(19,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 1      "; gotoxy(19,12); break;
		case 'W': gotoxy(27,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 2      "; gotoxy(27,12); break;
		case 'E': gotoxy(35,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 3      "; gotoxy(35,12); break;
		case 'R': gotoxy(43,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 4      "; gotoxy(43,12); break;
		case 'T': gotoxy(51,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 5      "; gotoxy(51,12); break;
		case 'Y': gotoxy(59,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 6      "; gotoxy(59,12); break;
		case 'U': gotoxy(67,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 7      "; gotoxy(67,12); break;
		case 'I': gotoxy(75,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 8      "; gotoxy(75,12); break;
		case 'O': gotoxy(83,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 9      "; gotoxy(83,12); break;
		case 'P': gotoxy(91,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 10     "; gotoxy(91,12); break;
		case (char)239: gotoxy(99,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 11     "; gotoxy(99,12); ingresar=getch(); break;
		case '+': gotoxy(107,12); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 2, columna 12     "; gotoxy(107,12); break;
		case 'A': gotoxy(23,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 1      "; gotoxy(23,16); break;
		case 'S': gotoxy(31,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 2      "; gotoxy(31,16); break;
		case 'D': gotoxy(39,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 3      "; gotoxy(39,16); break;
		case 'F': gotoxy(47,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 4      "; gotoxy(47,16); break;
		case 'G': gotoxy(55,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 5      "; gotoxy(55,16); break;
		case 'H': gotoxy(63,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 6      "; gotoxy(63,16); break;
		case 'J': gotoxy(71,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 7      "; gotoxy(71,16); break;
		case 'K': gotoxy(79,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 8      "; gotoxy(79,16); break;
		case 'L': gotoxy(87,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 9      "; gotoxy(87,16); break;
		case (char)165: gotoxy(95,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 10     "; gotoxy(95,16); break;
		case '{': gotoxy(103,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 11     "; gotoxy(103,16); break;
		case '}': gotoxy(111,16); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 3, columna 12     "; gotoxy(111,16); break;
		case 'Z': gotoxy(27,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 1      "; gotoxy(27,20); break;
		case 'X': gotoxy(35,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 2      "; gotoxy(35,20); break;
		case 'C': gotoxy(43,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 3      "; gotoxy(43,20); break;
		case 'V': gotoxy(51,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 4      "; gotoxy(51,20); break;
		case 'B': gotoxy(59,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 5      "; gotoxy(59,20); break;
		case 'N': gotoxy(67,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 6      "; gotoxy(67,20); break;
		case 'M': gotoxy(75,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 7      "; gotoxy(75,20); break;
		case ',': gotoxy(83,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 8      "; gotoxy(83,20); break;
		case '.': gotoxy(91,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 9      "; gotoxy(91,20); break;
		case '-': gotoxy(99,20); printf("%c",178); gotoxy(38,26); cout<<"Presione la tecla ubicada en l"<<(char)161<<"nea 4, columna 10     "; gotoxy(99,20); break;
		}
		ingresar=getch();
		if (C==ingresar) { cout<<C; puntaje++; }
		else {cout<<"~"; error++; }
		cantidad++;
	}
	
	if (puntaje == 0){
		gotoxy(38,26); cout << "   *********************************                ";
		gotoxy(38,27); cout << "  ************* PERDISTE! ***********               ";
		gotoxy(38,28); cout << "   *********************************                ";
	}
	else{
		gotoxy(35,28); cout << " FELICITACIONES! Tu puntaje fue: " << puntaje;
	}

	if(puntaje <= 10){ nivel = "Principiante";
	}
	else { if(puntaje <= 23){ nivel = "Discipulo";
	}
	else { if (puntaje <= 35){ nivel = "Experto";
	}
	else { nivel = "Erudito";
	} } }
	
	gotoxy(37,30); cout <<" Nivel alcanzado en esta partida: " << nivel << endl;
	
	mayor=principal[nequipo].jugadores[nusuario].mejoresjugadas[0].maxpuntaje;
	if(puntaje>mayor){
		principal[nequipo].jugadores[nusuario].mejoresjugadas[0].maxpuntaje=puntaje;
	}
	
	principal[nequipo].jugadores[nusuario].mejoresjugadas[0].cantjugadas++;
	
	system("PAUSE");
	
	
	
	
	
	calcularl1(nequipo,0,principal,mayor);
	
	
	
	
}


void verInstruccionesTK (void){
	cout << " ---- TEKLADER ----> Instrucciones ---- " << endl << endl;
	cout << " El juego consiste en ir acertando las teclas alfanumericas que aparecen en un teclado virtual."<< endl;
	cout << " Durante el juego, se debe ingresar la tecla que esta resaltada,"<< endl;
	cout << " estas van apareciendo de manera totalmente aleatoria." << endl;
	cout << " El juego finaliza si el usuario no acierta en un total de cinco oportunnidades," << endl;
	cout << " o si logra completar el teclado ingresando las teclas correctamente." << endl << endl;
	cout << "  PUNTUACION" << endl;
	cout << " Por cada caracter alfanumérico acertado por el usuario se suma un punto." << endl;
	cout << " Pudiendo asi obtener un maximo de 47 puntos. "<< endl<<endl;
	
}

void EvolucionTK (int nequipo, int nusuario,equipo principal[]){
	int puntaje = principal[nequipo].jugadores[nusuario].mejoresjugadas[0].maxpuntaje;
	
	cout << "Cantidad de veces jugadas: " << principal[nequipo].jugadores[nusuario].mejoresjugadas[0].cantjugadas <<endl << endl;
	cout << "Puntaje maximo: " << principal[nequipo].jugadores[nusuario].mejoresjugadas[0].maxpuntaje <<endl<<endl;
	if(puntaje <= 10){ cout << "Nivel: Principiante" << endl;
	}
	else { if(puntaje <= 23){ cout << "Nivel: Discipulo" << endl ;
	}
	else { if (puntaje <= 35){ cout << "Nivel: Experto" << endl;
	}
	else { cout << "Nivel: Erudito"<< endl ;
	} } }
	
	system("PAUSE");
}
