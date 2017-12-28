#ifndef LOGO_H
#define LOGO_H

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include "general.h"

using namespace std;

char jump1[20][32] = {
	"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"00         ",
		"0000       ",
		"00000      ",
		"000000     ",
		"000000     ",
		"000000     ",
		"0000       ",
		"00         ",
		"           ",
		"           ",
		"           ",
		"           ",
};//35x 19y
char jump2[20][32] = {
	"                 ",
		"                 ",
		"                 ",
		"                 ",
		"00               ",
		"00000            ",
		"000000           ",
		"00000000         ",
		" 000000000       ",
		" 0000000000      ",
		"000000000000     ",
		"000000000000     ",
		"      000000     ",
		"    000000       ",
		" 0000000         ",
		"00000            ",
		"0                ",
		"                 ",
		"                 ",
};//35x 19y
char jump3[20][32] = {
	"                       ",
		"                       ",
		"00                     ",
		"000000                 ",
		"00000000               ",
		"00000000000            ",
		"000  0000000           ",
		"0000  00000000         ",
		"00000  000000000       ",
		"00000  0000000000      ",
		"000000000000000000     ",
		"000000000000000000     ",
		"            000000     ",
		"          000000       ",
		"       0000000         ",
		"  000000000            ",
		"0000000                ",
		"000                    ",
		"                       ",
};//35x 19y
char jump4[20][32] = {
	"                               ",
		"0 0 0                          ",
		"0000000000                     ",
		"00000000000000                 ",
		"0000000000000000               ",
		"0000000000000000000            ",
		"0000  00000  0000000           ",
		"00000  00000  00000000         ",
		"000000  00000  000000000       ",
		"000000  00000  0000000000      ",
		"00000000000000000000000000     ",
		"00000000000000000000000000     ",
		"00                  000000     ",
		"0                 000000       ",
		"00             0000000         ",
		"000       000000000            ",
		"000000000000000                ",
		"00000000000                    ",
		"                               ",
};//35x 19y
char jump[20][32] = {
	"                               ",
		"    0 0 0                      ",
		" 0000000000000                 ",
		"000000000000000000             ",
		"00000000000000000000           ",
		"00000000000000000000000        ",
		"00000000  00000  0000000       ",
		"000000000  00000  00000000     ",
		"0000000000  00000  000000000   ",
		"0000000000  00000  0000000000  ",
		"000000000000000000000000000000 ",
		"000000000000000000000000000000 ",
		"000000                  000000 ",
		"00000                 000000   ",
		"000000             0000000     ",
		"0000000       000000000        ",
		"0000000000000000000            ",
		"  0000000000000                ",
		"                               ",
};//31x 19y

char logo[14][84] = {
	"                                                                                  ",
		"       HHH                             HHH     HHH  HHHHHHHHHHH        HHH     HHH",
		"       HHH                             HHH     HHH  HHHHHHHHHHH        HHHH    HHH",
		"       HHH                             HHH     HHH      HHH            HHHHH   HHH",
		"       HHH                             HHH     HHH      HHH            HHHHHH  HHH",
		"       HHH  HH   HH   HHHHH    HHHHH   HHH     HHH      HHH    HHHHH   HHH HHH HHH",
		"       HHH  HH   HH  HH   HH  HH   HH  HHH     HHH      HHH   HH   HH  HHH  HHHHHH",
		"HHH    HHH  HH   HH  HHHHHH   HH   HH  HHH     HHH      HHH   HHHHHH   HHH   HHHHH",
		"HHHHHHHHHH  HH   HH  HH       HH   HH   HHHHHHHHH       HHH   HH       HHH    HHHH",
		" HHHHHHH     HHHHH    HHHHHH   HHHHHH    HHHHHHH        HHH    HHHHHH  HHH     HHH",
		"                                   HH                                             ",
		"                                HHHH                                              ",
		"                                                                                  ",
}; //82x 13y 

void pantalla_inicial(){
	// j = eje Y (filas)  -  i = eje X (columnas)
	//Visualización del Logo
	for(int j = 0 ; j< 14 ; j++){
		for(int i = 0 ; i < 84 ; i++) {
			//gotoxy(i+34,j+2); cout<< logo[j][i];
			if(logo[j][i] == 'H'){
				gotoxy(i+34,j+2); printf("%c",177);
			}
			else gotoxy(i+34,j+2); printf(" ");
		}
	}
	gotoxy(65,18); cout<< "VERSION 2.0 - 2016";
	gotoxy(4,22); cout<<"----------------------------------------------------------------------------------------------------------------";
	gotoxy(4,23); cout<<"----------------------------------------------------------------------------------------------------------------";
	gotoxy(52,26); cout<<"--> GRUPO 18 <--";
	gotoxy(28,29); cout<<"Molina Lucas          luks_m@live.com.ar               Comision B";
	gotoxy(28,31); cout<<"Perussini Martin      martin97_peru@hotmail.com        Comision B";
	gotoxy(28,33); cout<<"Ravelli Tomas         tomy_ravelli@hotmail.com         Comision B";
	
	Sleep(1200);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),114);
	
	//Visualización de Jump1
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 32 ; i++) {
			if(jump1[j][i] == '0'){
				gotoxy(i+2,j+2); printf("%c",176);
			}
			else gotoxy(i+2,j+2); printf(" ");
		}
	}
	//Visualización de Jump2
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 32 ; i++) {
			if(jump2[j][i] == '0'){
				gotoxy(i+2,j+2); printf("%c",176);
			}
			else gotoxy(i+2,j+2); printf(" ");
		}
	}
	//Visualización de Jump3
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 32 ; i++) {
			if(jump3[j][i] == '0'){
				gotoxy(i+2,j+2); printf("%c",177);
			}
			else gotoxy(i+2,j+2); printf(" ");
		}
	}
	//Visualización de Jump4
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 32 ; i++) {
			if(jump4[j][i] == '0'){
				gotoxy(i+2,j+2); printf("%c",177);
			}
			else gotoxy(i+2,j+2); printf(" ");
		}
	}
	//Visualización de Jump
	for(int j = 0 ; j< 20 ; j++){
		for(int i = 0 ; i < 32 ; i++) {
			if(jump[j][i] == '0'){
				gotoxy(i+2,j+2); printf("%c",178);
			}
			else gotoxy(i+2,j+2); printf(" ");
		}
	}
	system ("pause>null");
}


#endif
