#include <iostream>
#include <cstdlib>
#include "libjueguten.h"
using namespace std;
 //hola hhh
int menuprincipal(){
	int opcion;
	system("CLS");
	cout<<"JuegUTeN - Menu principal"<<endl;
	cout<<"*************************"<<endl<<endl;
	cout<<"1 - Registrarse"<<endl;
	cout<<"2 - Iniciar sesion"<<endl;
	cout<<"9 - Salir"<<endl<<endl;
	cout<<"Ingrese alguna opcion: ";
	cin>>opcion;
	while(opcion!=1 && opcion!=2 && opcion!=9){
		cout<<"Ingrese alguna opcion valida: ";
		cin>>opcion;
	}
	if(opcion==1)
		return 1;
	else{
		if(opcion==2)
			return 2;
		else{
			if(opcion==9)
				return 9;
		}
	}
	return 0;
}

void registro (equipo principal[]){
	system("CLS");
	int dianac,mesnac,anionac,numequipo;
	string key;
	char keyvec[10];
	cout<<endl<<"******REGISTRO******"<<endl<<endl;
	cout<<"Ingrese dia de nacimiento (DD)"<<endl;
	cin>>dianac;
	cout<<"Ingrese mes de nacimiento (MM)"<<endl;
	cin>>mesnac;
	cout<<"Ingrese a"<<char(164)<<"o de nacimiento (AAAA)"<<endl;
	cin>>anionac;
	while(fecha(dianac,mesnac,anionac)){
		cout<<"Fecha no valida, ingrese una fecha correcta"<<endl;
		cout<<endl;
		cout<<"Ingrese dia de nacimiento (DD)"<<endl;
		cin>>dianac;
		cout<<"Ingrese mes de nacimiento (MM)"<<endl;
		cin>>mesnac;
		cout<<"Ingrese a"<<char(164)<<"o de nacimiento (AAAA)"<<endl;
		cin>>anionac;
	}
	numequipo=asignacionequipo(dianac,mesnac);
	key=contra(numequipo, principal);
	if(key=="nadadenada"){
		return;
	}
	for(int i=0;i<10;i++){
		keyvec[i]=key[i];
	}
	//agrego jugador a equipo
	if(principal[numequipo].cantmiembros==5){
		cout<<"El equipo esta lleno"<<endl;
	}else{
		for(int i=0;i<10;i++){
			principal[numequipo].jugadores[principal[numequipo].cantmiembros].clave[i]=keyvec[i];
		}
		principal[numequipo].cantmiembros++;
		system("CLS");
		cout<<"Registro exitoso"<<endl;
		system("pause");
	}
}

bool fecha(int d,int m,int a){
	if(m==01 or m==03 or m==05 or m==07 or m==8 or m==10 or m==12){
		if(d>0 && d<=31 && a>=1900 && a<=2016){
			return false;
		}
	}
	else{
		if(m==04 or m==06 or m==9 or m==11){
			if(d>0 && d<=30 && a>=1900 && a<=2016){
				return false;
			}
		}
		else{
			if(m==02){
				if(a>=1900 && a<=2016 && a%4==0){
					if(d>0 && d<=29){
						return false;
					}
				}
				else{
					if(a>=1900 && a<=2015 && d>0 && d<=28){
						return false;
					}
				}
			}
			else{
				return true;
			}
		}
	}
	return true;
}
int asignacionequipo(int d,int m){
	switch(m){
	case 1: if(d<=9){
		cout<<"Equipo Lagarto"<<endl;
		return 9;
	}else{
		cout<<"Equipo Gorila"<<endl;
		return 10;
	}
	break;
	case 2: if(d<=6){
		cout<<"Equipo Gorila"<<endl;
		return 10;
	}else{
		cout<<"Equipo Halcon"<<endl;
		return 11;
	}
	break;
	case 3: if(d<=6){
		cout<<"Equipo Halcon"<<endl;
		return 11;
	}else{
		cout<<"Equipo Jaguar"<<endl;
		return 12;
	}
	break;
	case 4: if(d<=3){
		cout<<"Equipo Jaguar"<<endl;
		return 12;
	}else{
		cout<<"Equipo Zorro"<<endl;
		return 0;
	}
	break;
	case 5: if(d==1){
		cout<<"Equipo Zorro"<<endl;
		return 0;
	}else{
		if(d>=2 && d<=29){
			cout<<"Equipo Serpiente"<<endl;
			return 1;
		}
		else{
			cout<<"Equpo Ardilla"<<endl;
			return 2;
		}
	}
	break;
	case 6: if(d<=26){
		cout<<"Equipo Ardilla"<<endl;
		return 2;
	}else{
		cout<<"Equipo Tortuga"<<endl;
		return 3;
	}
	break;
	case 7: if(d<=25){
		cout<<"Equipo Tortuga"<<endl;
		return 3;
	}else{
		cout<<"Equipo Murcielago"<<endl;
		return 4;
	}
	break;
	case 8: if(d<=22){
		cout<<"Equipo Murcielago"<<endl;
		return 4;
	}else{
		cout<<"Equipo Alacran"<<endl;
		return 5;
	}
	break;
	case 9: if(d<=19){
		cout<<"Equipo Alacran"<<endl;
		return 5;
	}else{
		cout<<"Equipo Venado"<<endl;
		return 6;
	}
	break;
	case 10: if(d<=17){
		cout<<"Equipo Venado"<<endl;
		return 6;
	}else{
		cout<<"Equipo Lechuza"<<endl;
		return 7;
	}
	break;
	case 11: if(d<=14){
		cout<<"Equipo Lechuza"<<endl;
		return 7;
	}else{
		cout<<"Equipo Gallo"<<endl;
		return 8;
	}
	break;
	case 12: if(d<=12){
		cout<<"Equipo Gallo"<<endl;
		return 8;
	}else{
		cout<<"Equipo Lagarto"<<endl;
		return 9;
	}
	break;
	}
	return 0;
}
string contra(int team, equipo principal[]){
	string clave;
	int intentos=1;
	cout<<endl<<"Ingrese una clave"<<endl;
	cin>>clave;
	while(!valida(clave,team,principal) && intentos<3){
		cout<<"Ingrese una clave valida"<<endl;
		intentos++;
		cin>>clave;
	}
	if(intentos==3){
		system("CLS");
		cout<<"Fallaste en los 3 intentos, prueba de nuevo"<<endl;
		system("pause");
		system("CLS");
		return "nadadenada";
	}
	cout<<"Clave Valida :D"<<endl<<endl;
	system("pause");
	return clave;
}
bool valida (string clave, int team, equipo principal[]){
	string error;
	
	int con=0, i=0, contadorsinton=0, conmay=0, connum=0, numseg=0, regla1=0, tamclave=clave.size();
	
	for(int i=0;i<5;i++){
		if(principal[team].jugadores[i].clave==clave){
			regla1++;
		}
	}
	if(regla1>0){
		error=error+"regla #1: otro jugador ya usa esta clave. ";
		con++;
	}
	if(clave.size()<4){
		con++;
		error=error+"regla #2:minimo 4 caracteres.  ";}
	if(clave.size()>10){
		con++;
		error=error+"regla #3:maximo 10 caracteres. ";}
	while(i<tamclave){
		if((clave[i]<'a' or clave[i]>'z') && (clave[i]<'A' or clave[i]>'Z') && (clave[i]<'0' or clave[i]>'9')){
			con++;
			contadorsinton++;
		}
		if(clave[i]>='A' && clave[i]<='Z')
			conmay++;
		if(clave[i]>='0' && clave[i]<='9')
			connum++;
		if((clave[i]>='0' && clave[i]<='9') && (clave[i+1]>='0' && clave[i+1]<='9')){
			con++;
			numseg++;
		}
		i++;
	}
	if(contadorsinton>0)
		error=error+"regla #4:solo minusculas, mayusculas y numeros. ";
	if(conmay<2){
		con++;
		error=error+"Regla #5:al menos 2 mayusculas. ";
	}
	if(connum<2){
		con++;
		error=error+"Regla #6:al menos 2 numeros. ";
	}
	if(numseg!=0){
		error=error+"Regla #7:los numeros no pueden estar seguidos. ";
	}
	
	int k=0,n=0,l=0,conn=0,conl=0;
	while(clave[k]!=0){
		if(clave[k]>='0' && clave[k]<='9'){
			n+=clave[k];
			conn++;
		}else{
			if((clave[k]>='a' && clave[k]<='z') or (clave[k]>='A' && clave[k]<='Z')){
				l+=clave[k];
				conl++;
			}
		}
		k++;
	}
	if(conn!=0 && conl!=0){
		n=n/conn;
		l=l/conl;
		if(abs(n-l)>=50){
			con++;
			error=error+"Regla #8:clave inestable. ";
		}
	}else{
		con++;
		error=error+"Regla #8:clave inestable. ";
	}
	
	cout<<error<<endl;
	if(con==0)
		return true;
	else
		return false;
}

void sesion(equipo principal[]){
	system ("CLS");
	string ne,key;
	int teamn=0,numusuario;
	cout<<endl<<"******INICIO DE SESION******"<<endl<<endl;
	cout<<"Ingrese el nombre de su equipo: "<<endl;
	cin>>ne;
	ne=pasaraminuscula(ne);
	teamn=cualequipo(ne);
	while(teamn<0){
		cout<<"Ingrese un equipo valido: "<<endl;
		cin>>ne;
		ne=pasaraminuscula(ne);
		teamn=cualequipo(ne);
	}
	cout<<"Ingrese su clave de usuario: "<<endl;
	cin>>key;
	numusuario=cualkey(key,teamn,principal);
	if(numusuario==-1){
		system("pause");
		system("CLS");
		return;
	}
	system("CLS");
	cout<<"Inicio de sesion exitoso"<<endl;
	system("pause");
	menudejuegos(teamn,numusuario,principal);
}
string pasaraminuscula(string x){
	int i=0,tamdex=x.size();
	while(i<tamdex){
		if(x[i]>='A' and x[i]<='Z'){
			x[i]+=32;
		}
		i++;
	}
	return x;
}
int cualequipo(string t){
	int f;
	if(t=="zorro"){
		f=0;
	}else{
		if(t=="serpiente"){
			f=1;
		}else{
			if(t=="ardilla"){
				f=2;
			}else{
				if(t=="tortuga"){
					f=3;
				}else{
					if(t=="murcielago"){
						f=4;
					}else{
						if(t=="alacran"){
							f=5;
						}else{
							if(t=="venado"){
								f=6;
							}else{
								if(t=="lechuza"){
									f=7;
								}else{
									if(t=="gallo"){
										f=8;
									}else{
										if(t=="lagarto"){
											f=9;
										}else{
											if(t=="gorila"){
												f=10;
											}else{
												if(t=="halcon"){
													f=11;
												}else{
													if(t=="jaguar"){
														f=12;
													}else{
														f=-1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return f;
}
int cualkey(string k,int eq,equipo principal[]){
	int j=0,encontrada=0,retorno;
	while(j<5 and encontrada==0){
		if(principal[eq].jugadores[j].clave==k){
			retorno=j;
			encontrada++;
		}
		j++;
	}
	if(encontrada==0){
		cout<<"Esa clave no correspondo a ningun usuario"<<endl;
		return -1;
	}else{
		return retorno;
	}
}
void menudejuegos(int nequipo,int nusuario,equipo principal[]){
	int opcion=0;
	
	while(opcion!=9){
		system("CLS");
		cout<<endl<<"JuegUTeN - Menu de Juegos"<<endl;
		cout<<"*************************"<<endl<<endl;
		cout<<"1) Simon"<<endl;
		cout<<"2) Teklader"<<endl;
		cout<<"3) KingCoder"<<endl;
		cout<<"4) Insignias"<<endl<<endl;
		cout<<"9) Cerrar sesion"<<endl<<endl;
		cout<<"*************************"<<endl<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=9){
			cout<<"Ingrese alguna opcion valida: ";
			cin>>opcion;
		}
		if(opcion==3){
			KingCoder(nequipo, nusuario, principal);
		}else{
			if(opcion==1){
				simon(nequipo, nusuario, principal);
			}else{
				if(opcion==2){
					teklader(nequipo, nusuario, principal);
				}else{
					if(opcion==4){
						calcularinsigniasmenu(nequipo,principal);
					}
				}
			}
		}
	}
	return;
}
void calcularinsigniasmenu(int nequipo,equipo principal[]){
	
	int opcion=0;
	while(opcion!=9){
		system("CLS");
		cout<<"Menu de insignias"<<endl<<endl;
		cout<<"1) Insignias de mi equipo"<<endl;
		cout<<"2) Insignias de todos los equipos"<<endl<<endl;
		cout<<"9) Salir"<<endl<<endl;
		cin>>opcion;
		while(opcion!=1 && opcion!=2 && opcion!=9){
			cout<<"Ingrese alguna opcion valida: ";
			cin>>opcion;
		}
		if(opcion==1){
			insigniasequipo(nequipo,principal);
		}else{
			if(opcion==2){
				insigniastotal(principal);
			}
		}
	}
}
void insigniasequipo(int nequipo,equipo principal[]){
	system("CLS");
	cout<<"Tu equipo en este momento posee:"<<endl<<endl;
	cout<<"Cantidad de insignias l1 en Teklader: "<<principal[nequipo].medallas[0]<<endl;
	cout<<"Cantidad de insignias l1 en Simon: "<<principal[nequipo].medallas[1]<<endl;
	cout<<"Cantidad de insignias l1 en Kingcoder: "<<principal[nequipo].medallas[2]<<endl<<endl;
	if(calculoplata(nequipo,principal)){
		cout<<"Tu equipo posee la insignia de plata"<<endl;
	}else{
		cout<<"Tu equipo no posee la insignia de plata"<<endl;
	}
	system("pause");
}
void insigniastotal(equipo principal[]){
	system("CLS");
	for(int i=0;i<13;i++){
		cout<<"Insignias equipo: "<<principal[i].nombre<<endl;
		cout<<"Cantidad de insignias l1: ";
		cout<<"TK: "<<principal[i].medallas[0]<<" - SM: "<<principal[i].medallas[1]<<" - KC: "<<principal[i].medallas[2]<<endl;
		if(calculoplata(i,principal)){
			cout<<"Posee la insignia l2"<<endl;
		}else{
			cout<<"No posee la insignia l2"<<endl;
		}
		cout<<"***********************************"<<endl;
	}
	system("pause");
}
bool calculoplata(int nequipo,equipo principal[]){
	int contadormedalla=0,eruditosimon=210,eruditoteklader=35,eruditokingcoder=70;
	for(int i=0;i<3;i++){
		if(principal[nequipo].medallas[i]>=3){
			contadormedalla++;
		}
	}
	
	int aux,contadoreruditos=0;
	
	if(contadormedalla==3){
		for(int i=0;i<principal[nequipo].cantmiembros;i++){
			int erudito3=0;
			for(int j=0;j<3;j++){
				if(j==0){
					aux=eruditoteklader;
				}else{
					if(j==1){
						aux=eruditosimon;
					}else{
						aux=eruditokingcoder;
					}
				}
				if(principal[nequipo].jugadores[i].mejoresjugadas[j].maxpuntaje>aux){
					erudito3++;
				}
			}
			if(erudito3==3){
				contadoreruditos++;
			}
		}
	}
	if(contadormedalla==3 && contadoreruditos>=(((float)principal[nequipo].cantmiembros)/2)){
		return true;
	}else{
		return false;
	}
}
