/*
CHABOTSMX -[:]
          ||
          ||
||||||||||||||||||||||
||                  ||

||   ()        ()   ||
||||||||||||||||||||||
Las 3.14159zzas de chaBots
*/
#ifndef MOTOR_H
#define MOTOR_H
#include "C:\3.14159zzas\3.14159zzas\main\ai.h"

typedef struct Motor{ /*Constructor de la estructura Motor.*/
	int side;/*A que lado corresponde.*/
};

void asignarMotor(struct Motor *motor,int speed); /*Asigna una velocidad a un motor determinado.*/
#endif
