#include "kingcoder.h"
#include <cstdlib>
#include <fstream>
#include <ctime>



void instruccionesKC() {
	system("cls");
	cout << "		Instrucciones - KingCoder" << endl;
	cout << "		========================" << endl << endl << endl;
	cout << "	Descripci" << (char) 162 << "n:" << endl;
	cout << "	-----------" << endl;
	cout << "	King Coder consiste en un juego donde debes encontrar los errores en 5 codigos escritos en el lenguaje " << endl; 
	cout << "	de programacion C++. " << endl; 
	cout << "	Una vez que lees el codigo y encuentras los errores dentro de este, debes indicar en que lineas has " << endl; 
	cout << "	encontrado las fallas, finalizando con un '0' cuando no encuentras mas errores." << endl; 
	cout << endl<<"		PUNTUACION." << endl; 
	cout << " 	El metodo de puntuacion es sencillo: solamente sumas puntos (20) en caso de acertar/encontrar todos los errores sino" << endl; 
	cout << "	 No sumas puntos." << endl; 
	cout << endl;

}

void jugarKC(int nequipo, int nusuario,equipo principal[]){
	system("cls");
		Codigo codigos[CODS];
		int cant=0,i,opcion,jugadas, linea ,puntaje = 0,j,acertado,contadorjug=0,mayor,errordescubierto=0,lineadescubierta=0;
		bool cargarcod;
		string nivelKC;
		cargarcod 	= cargarCodigos(codigos,cant);
		
		for(jugadas  = 0; jugadas < JUGKC;jugadas++){
			acertado=0;
			
			srand(time(NULL));
			opcion = rand()%cant;
			
			for(i=0;i<codigos[opcion].cantLineas;i++){
				
				cout << codigos[opcion].lineas[i] << endl;
				
			} 
			
			cout << "Ingrese las lineas con errores (finaliza con '0'): " << endl;
			cout << endl<<"_ ";
			cin >> linea;
			
			while (linea != 0 ){
				for(j=0;j<codigos[opcion].cantErrores; j++){
					if(linea == codigos[opcion].errores[j]){
						acertado++;	
						lineadescubierta++;
						codigos[opcion].errores[j] = 0;
					}
				}
				cout << "_ ";
				cin >> linea;
			}
			if(acertado == codigos[opcion].cantErrores ){
				puntaje+=20;
				contadorjug++;
			}
			if(lineadescubierta > 0){
				errordescubierto++;
			}
			lineadescubierta=0;
			
			system("PAUSE");
			system("CLS");
		}
		
		cout << "--------- RESULTADOS JUGADA ---------" <<endl;
		
		cout << endl << "*   Jugadas Completadas: " << contadorjug<<endl;
		
		cout << endl <<"*   El puntaje obtenido es: " << puntaje<<endl;
		
		
		if(puntaje<=20){
			nivelKC ="Principiante";
		}
		else 
			if(puntaje > 20 && puntaje <= 50){
			nivelKC ="Discipulo";
		}
			else if(puntaje>50 && puntaje <= 70){
			nivelKC ="Experto";
		}
			else nivelKC ="Erudito";
		
	cout <<endl<< "*   Nivel Alcanzado: " <<nivelKC<<"." << endl;
		
		mayor=principal[nequipo].jugadores[nusuario].mejoresjugadas[2].maxpuntaje;
		if(puntaje>mayor){
			principal[nequipo].jugadores[nusuario].mejoresjugadas[2].maxpuntaje=puntaje;
		}
		
				
	principal[nequipo].jugadores[nusuario].mejoresjugadas[2].cantjugadas++;	
		
		
	calcularl1(nequipo,2,principal,mayor);
		
	
	cout <<endl << " ////////////////////////////////////// "<< endl;
	cout << endl <<"_ Cantidad de codigos que se descubrieron errores: " << errordescubierto<<endl;
	cout << endl <<"_ Cantidad de codigos que no se descubrieron errores: " << (5-errordescubierto)<<endl;
	cout << endl <<"_ Puntaje: " << puntaje<<endl;
	if(puntaje <= mayor || nivelKC=="Erudito"){
	cout << endl <<"_ Mantiene el mismo nivel en KingCoder: " <<nivelKC <<endl;
	}else
		if(puntaje>20 && puntaje<=40){
		cout << "_ Felicitaciones! Has subido de Nivel. Ahora eres: " << nivelKC <<endl;
	}
		else 
			if( puntaje >40 && puntaje <=60){
		cout << "_ Felicitaciones! Has subido de Nivel. Ahora eres: " << nivelKC <<endl;
	}
			else if( puntaje >60 && puntaje <= 80){
		cout << "_ Felicitaciones! Has subido de Nivel. Ahora eres: " << nivelKC <<endl;
	}
			else 
				cout << "_ Felicitaciones! Has subido de Nivel. Ahora eres: " << nivelKC <<endl;
	system("pause");
	system("CLS");
	
	
}

bool cargarCodigos(Codigo codigos[CODS], int & cant) {
	
		bool rta=true, acabado=false;
		int i=0, e, tam;
		
		string aux;
		
		ifstream fcodigos;
		fcodigos.open("kingcoder.txt");
		if(fcodigos.fail())
			rta=false;
		else {
			inicializar(codigos);
			
			cant=0;
			getline(fcodigos, aux,'\n');
			
			if(fcodigos.eof())
				acabado=true;
			else
				codigos[cant].lineas[i++]=aux;
			
			while(!acabado) {
				getline(fcodigos, aux,'\n');
				if(fcodigos.eof())
					acabado=true;
				if(aux[0]=='E')  {
					codigos[cant].cantLineas=i;
					aux=aux.substr(9,100);
					tam=aux.length();
					e=0; //para recorrer codigo.errores
					while(aux.length()>0) {
						if(aux.substr(0,1)!="-") {
							codigos[cant].errores[e]=aux[0]-48; //le resto 48 porque devuelve el orden ascii
							aux=aux.substr(1,tam);
							if(aux.length()>0) { //por el último caso
								if(aux.substr(0,1)!="-") {
									codigos[cant].errores[e]=(codigos[cant].errores[e]*10)+(aux[0]-48);
									aux=aux.substr(1,tam);
								}
								
							}
							e++;
							
						}
						else
							aux=aux.substr(1,tam);
					}
					codigos[cant].cantErrores = e;
					cant++;
					i=0;
					
					
				}
				else
					codigos[cant].lineas[i++]=aux;
			}
			fcodigos.close();
		}	
		return rta;
	}
	
void KingCoder(int nequipo, int nusuario,equipo principal[]){
	system("Cls");
	int menu=0;
	while (menu!=9){
		
		menu = menuJuegoKC(menu);	
		while(menu!=1 && menu!=2 && menu!=3 && menu!=9){
			cout<< endl << "Error! Ingrese una opcion valida." << endl<<endl;
			system("pause");
			system("cls");
			menu = menuJuegoKC(menu);
		}
		system("CLS");
		if(menu == 1){
			instruccionesKC();
			system("PAUSE");
			system("CLS");
		}
		else 
			if(menu == 2){
			
			jugarKC( nequipo,  nusuario, principal);	
		}
			else
				if(menu == 3){
			verEvolucionKC(nequipo, nusuario,principal);
		}
		system("CLS");
	}
	
}
	
int menuJuegoKC(int menu){
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

void verEvolucionKC(int nequipo,int nusuario,equipo principal[]){
	int puntajejugada = principal[nequipo].jugadores[nusuario].mejoresjugadas[2].maxpuntaje;
	
	cout << "Cantidad de veces jugadas: " << principal[nequipo].jugadores[nusuario].mejoresjugadas[2].cantjugadas << endl;
	cout << endl << "Puntaje maximo: " <<principal[nequipo].jugadores[nusuario].mejoresjugadas[2].maxpuntaje << endl;
	cout << endl;
	if(puntajejugada <= 20){
		cout << "Nivel: Principiante" << endl;
	}
	else
		if(puntajejugada >20 && puntajejugada <= 50){
		cout <<  "Nivel: Discipulo" << endl ;
	}
		else if (puntajejugada > 50 && puntajejugada <= 70){
		cout <<  "Nivel: Experto"<<endl;
	}
		else if(puntajejugada>70){
		cout << "Nivel: Erudito"<< endl ;
	}
	system("PAUSE");
}

void inicializar(Codigo codigos[]){
	int i,j;
	for(i=0; i<codigos[i].cantLineas ; i++){
		for(j=0; j<codigos[i].cantLineas;j++){
		codigos[i].lineas[j] = "NULL";
		codigos[i].errores[j] = 0;
		}
		codigos[i].cantErrores=0;
		codigos[i].cantLineas=0;
	}
}
