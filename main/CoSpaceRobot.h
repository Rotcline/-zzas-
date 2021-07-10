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
#ifndef CoSpaceRobot
#define CoSpaceRobot
#include "C:\3.14159zzas\3.14159zzas\main\ai.h"
#include "C:\3.14159zzas\3.14159zzas\main\Motor.h"
#include "C:\3.14159zzas\3.14159zzas\main\SColor.h"
#include "C:\3.14159zzas\3.14159zzas\main\SUltrasonico.h"
#include "C:\3.14159zzas\3.14159zzas\main\Compass.h"

extern struct Motor LMotor;
extern struct Motor RMotor;

int valueSColor(int side); /*Retorna el color que observa el robot.*/
int recogeRobot(/*int time*/); /*Recoge puntos del escenario.*/
int depositarRobot(/*int time*/); /*Deposita puntos.*/
int avanzaRobot(int speed); /*Avanza a la velocidad indicada en el argumento. Valores de 1-5. */
int turnRobot(int setPoint);/*Gira los grados indicados de manera no relativa en el argumento. Valores de 1-360.*/
int initRobot();/*Inicializa variables del robot.*/
int turnRRobot(int grados);/*Gira los grados indicados en el argumento de manera relativa. Valores de 1-360.*/
int currentAction();/*Maneja los estados en los que se encuentra el robot y ayuda a realizar el deposito del Robot*/
int verifyDuration();/*Verifica que sea la duración de la accion actual*/

#endif
