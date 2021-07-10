#include "C:\3.14159zzas\3.14159zzas\main\SColor.h"
#define Rojo 0 //objeto
#define Cyan 1 //objeto
#define Negro 2 //objeto
#define Naranja 3 //zona de deposito
#define Amarillo 4 //alerta de trampa
#define Gris 5 //zona que disminuye velocidad
#define Azul 6 //zona de doble puntaje
#define AzulM 7 //trampa
#define der 0
#define izq 1
#define minR 0
#define maxR 1
#define minG 2
#define maxG 3
#define minB 4
#define maxB 5

int rangosColor[8][6] = {
/////minR maxR minG maxG minB maxB
	{230, 255,  20,  50,  20,  50}, //Rojo
	{ 0,  40, 230, 250, 0, 40}, //Cyan
	{ 20,  60,  20,  60,  20,  60}, //Negro
	{200, 240, 120, 190,   0,  10}, //Naranja
	{200, 240, 200, 250,   0,  30}, //Amarillo
	{130, 170, 145, 170, 185, 220}, //Gris
	{  0,  10, 140, 170, 240, 255}, //Azul
	{  0,  50, 0, 50, 190, 255}, //AzulM
};

int detectColor(struct SColor *scolor){
	if(*(scolor->r) >= rangosColor[Rojo][minR] && *(scolor->r) <= rangosColor[Rojo][maxR] && *(scolor->g) >= rangosColor[Rojo][minG] && *(scolor->g) <= rangosColor[Rojo][maxG] && *(scolor->b) >= rangosColor[Rojo][minB] && *(scolor->b) <= rangosColor[Rojo][maxB]) //Rojo
	    return Rojo;
	if(*(scolor->r) >= rangosColor[Cyan][minR] && *(scolor->r) <= rangosColor[Cyan][maxR] && *(scolor->g) >= rangosColor[Cyan][minG] && *(scolor->g) <= rangosColor[Cyan][maxG] && *(scolor->b) >= rangosColor[Cyan][minB] && *(scolor->b) <= rangosColor[Cyan][maxB]) //Cyan
	    return Cyan;
	if(*(scolor->r) >= rangosColor[Azul][minR] && *(scolor->r) <= rangosColor[Azul][maxR] && *(scolor->g) >= rangosColor[Azul][minG] && *(scolor->g) <= rangosColor[Azul][maxG] && *(scolor->b) >= rangosColor[Azul][minB] && *(scolor->b) <= rangosColor[Azul][maxB]) //Azul
	    return Azul;
	if(*(scolor->r) >= rangosColor[Negro][minR] && *(scolor->r) <= rangosColor[Negro][maxR] && *(scolor->g) >= rangosColor[Negro][minG] && *(scolor->g) <= rangosColor[Negro][maxG] && *(scolor->b) >= rangosColor[Negro][minB] && *(scolor->b) <= rangosColor[Negro][maxB]) //Negro
	    return Negro;
	if(*(scolor->r) >= rangosColor[Amarillo][minR] && *(scolor->r) <= rangosColor[Amarillo][maxR] && *(scolor->g) >= rangosColor[Amarillo][minG] && *(scolor->g) <= rangosColor[Amarillo][maxG] && *(scolor->b) >= rangosColor[Amarillo][minB] && *(scolor->b) <= rangosColor[Amarillo][maxB]) //Amarillo
	    return Amarillo;
	if(*(scolor->r) >= rangosColor[Gris][minR] && *(scolor->r) <= rangosColor[Gris][maxR] && *(scolor->g) >= rangosColor[Gris][minG] && *(scolor->g) <= rangosColor[Gris][maxG] && *(scolor->b) >= rangosColor[Gris][minB] && *(scolor->b) <= rangosColor[Gris][maxB]) //Gris
	    return Gris;
	if(*(scolor->r) >= rangosColor[Naranja][minR] && *(scolor->r) <= rangosColor[Naranja][maxR] && *(scolor->g) >= rangosColor[Naranja][minG] && *(scolor->g) <= rangosColor[Naranja][maxG] && *(scolor->b) >= rangosColor[Naranja][minB] && *(scolor->b) <= rangosColor[Naranja][maxB]) //Naranja
	    return Naranja;
	if(*(scolor->r) >= rangosColor[AzulM][minR] && *(scolor->r) <= rangosColor[AzulM][maxR] && *(scolor->g) >= rangosColor[AzulM][minG] && *(scolor->g) <= rangosColor[AzulM][maxG] && *(scolor->b) >= rangosColor[AzulM][minB] && *(scolor->b) <= rangosColor[AzulM][maxB]) //AzulM
	    return AzulM;
}
