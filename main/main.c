#include <stdio.h>
#include <stdlib.h>
#include "C:\3.14159zzas\3.14159zzas\main\main.h"
#include "C:\3.14159zzas\3.14159zzas\main\CoSpaceRobot.h"
#define LEFT 0
#define RIGHT 1
#define Rojo 0 //objeto
#define Cyan 1 //objeto
#define Negro 2 //objeto
#define Naranja 3 //zona de deposito
#define Amarillo 4 //alerta de trampa
#define Gris 5 //zona que disminuye velocidad
#define Azul 6 //zona de doble puntaje
#define AzulM 7 //trampa
#define LimiteX 350
#define LimiteY 250
#include <math.h>
#define PI 3.14159265
int casoActual=1;
int Duracion=0;
int SetupEjecutado=0;
int boolBarracuda=0;
int contadorBarracuda=0;
int boolOrange=0;
int r=0;
/*Este archivo es para definir el conductor, el ejecutador y el maestro */
      /*no trampas  v*/
//270 x 360

void barracuda(int wide){
	if(boolBarracuda==1){
			asignarMotor(&RMotor,2);
			asignarMotor(&LMotor,4);
			contadorBarracuda++;
			if(contadorBarracuda>wide){
				boolBarracuda=0;
				contadorBarracuda=0;
			}
	}
	else if (boolBarracuda==0){
			asignarMotor(&RMotor,4);
			asignarMotor(&LMotor,2);
			contadorBarracuda++;
			if(contadorBarracuda>wide){
				boolBarracuda=1;
				contadorBarracuda=0;
			}
	}
}

void irAZonaNaranja1(){
	if(boolOrange==0){
		turnRobot(0);
		if(gradosCompass()<5||gradosCompass()>355)
			boolOrange=1;
	}
	if(boolOrange==1){
		avanzaRobot(3);
		if(US_Front<15)
			boolOrange=2;
  }
	if(boolOrange==2){
		turnRobot(90);
		if(gradosCompass()>90-10&&gradosCompass()<90+10)
			boolOrange=3;
	}
	if(boolOrange==3){
			avanzaRobot(3);
		if(US_Front<15)
			boolOrange=4;
	}
	if(boolOrange==4){
    turnRobot(180);
		if(gradosCompass()>180-10&&gradosCompass()<180+10)
			boolOrange=5;
	}
  if(boolOrange==5){
    avanzaRobot(3);
    if(US_Front<15)
      boolOrange=6;
  }
  if(boolOrange==6){
    turnRobot(90);
    if(gradosCompass()>90-10&&gradosCompass()<90+10)
      boolOrange=7;
  }
  if(boolOrange==7){
    avanzaRobot(3);
    if(US_Front<15)
      boolOrange=8;
  }
  if(boolOrange==8){
    turnRobot(0);
    if(gradosCompass()<5||gradosCompass()>355)
      boolOrange=9;
  }
  if(boolOrange==9){
    avanzaRobot(3);
    if(US_Front<15)
      boolOrange=10;
  }
  if(boolOrange==10){
    turnRobot(270);
    if(gradosCompass()>270-10&&gradosCompass()<270+10)
      boolOrange=11;
  }
  if(boolOrange==11){
    avanzaRobot(3);
    if(US_Front<15)
      boolOrange=12;
  }
	if(boolOrange==12){
		if(US_Front<15){
			boolOrange=1;
		}
		else{
			avanzaRobot(3);
		}
	}
}

void irDeXAY(int x, int y){
	float dx = x - PositionX;
	float dy = y - PositionY;
  float m = dy/dx;
	if(((dx < 0 && dx > -10) && (dy > 0 && dy < 10)|| (dx > 0 && dx < 10)) && ((dy < 0 && dy < -10)))
		return;
	float angle = atan(m);
	angle = angle*(180/PI);
  if(PositionX<x)
	 angle = ((int)angle+270)%360;
  else
    angle = ((int)angle+90)%360;

	if(gradosCompass()==angle)
		avanzaRobot(4);
	else
		turnRobot(angle);
}

void cambioDeMundo(int TiempoDeCambio){
  if(Time>TiempoDeCambio)
    Teleport=1;
}

void checkUSSensor(){
	if(US_Front<7||US_Right<7||US_Left<7){
		avanzaRobot(-5);
	}
	else if(US_Front<=10||US_Right<=10){
		asignarMotor(&LMotor,0);
		asignarMotor(&RMotor,5);
	}
	else if(US_Left<=10){
		asignarMotor(&LMotor,5);
		asignarMotor(&RMotor,0);
	}
	else{
		barracuda(10);
	}
}

int checkColors(){
	if(valueSColor(LEFT)==Rojo||valueSColor(RIGHT)==Rojo||valueSColor(LEFT)==Cyan||valueSColor(RIGHT)==Cyan||valueSColor(LEFT)==Negro||valueSColor(RIGHT)==Negro)
	{
		recogeRobot();
	}
	if(valueSColor(LEFT)==AzulM||valueSColor(RIGHT)==AzulM)
	{
		LoadedObjects=0;
	}
	if(valueSColor(LEFT)==Naranja&&valueSColor(RIGHT)==Naranja)
	{
		depositarRobot();
	}
	if(valueSColor(LEFT)==Gris&&valueSColor(RIGHT)==Gris)
	{
		turnReverseRRobot(100);
	}
	if(LoadedObjects>0)
	{
		if(valueSColor(LEFT)==Amarillo)
		{
			asignarMotor(&LMotor,0);
			asignarMotor(&RMotor,-5);
			return 1;
		}
		if(valueSColor(RIGHT)==Amarillo)
		{
			asignarMotor(&LMotor,-5);
			asignarMotor(&RMotor,0);
			return 1;
		}
	}
	return 0;
}

void setup(){
  if(SetupEjecutado==0)
  {
    initRobot();
  }
  SetupEjecutado==1;
}

void automaticPilotMundo1(){
    cambioDeMundo(299);
		if(LoadedObjects==6)
			irAZonaNaranja1();
		else
    	checkUSSensor();
}

void automaticPilotMundo2(){
	if(PositionX<10||PositionY<10||PositionX>350||PositionY>260){
		turnReverseRRobot(90);
	}
  else
		if(LoadedObjects==6)
			irDeXAY(278,131);
		else
			checkUSSensor();
}

void proof(int world){
  setup();
	if(CurAction!=-1){
		verifyDuration();
		currentAction();
	}
	else{
		if(checkColors()==1){}
		else{
			if(world==1){
		    automaticPilotMundo1();
			}
		  else if(world==2){
		    automaticPilotMundo2();
			}
		}
	}
}
