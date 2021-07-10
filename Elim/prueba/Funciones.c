#include<stdio.h>
#include<stdlib.h>
#include"Funciones.h"
#include "D:\F.O.L.D.E.R\chaBots\Rescue-Simulation\mnm\3.14159zzas\Elim\prueba\ai.h"

void fwd(int speed){
  WheelLeft=speed;
  WheelRight=speed;

}

int turn(int side){
  switch (side) {
    case 1:
    if(Compass>=0 && Compass<80)
    {
      WheelRight=2-calcularPid(90,Compass,6,6);
      WheelLeft=0;
    }
    if(Compass>100 && Compass<=180)
    {
      WheelLeft=2;
      WheelRight=0;
    }
    if(Compass>180 && Compass<360)
    {
      WheelRight=2;
      WheelLeft=0;
    }
    if(Compass>80&&Compass<100)
    {
      return 1;
    }
    break;
  }
}

void drop(){
  LoadedObjects = 0;
}

void pick(){
  LoadedObjects++;
}

int colorDetect(){

  if((CSLeft_R>200 && CSLeft_G>200 && CSLeft_B>200) || (CSRight_R>200 && CSRight_G>200 && CSRight_B>200)) //WHITE
  {
    return 1;
  }
  if((CSLeft_R>240 && CSLeft_G<50 && CSLeft_B<50) || (CSRight_R>240 && CSRight_G<50 && CSRight_B<50)) //RED
  {
    return 2;
  }
  if((CSLeft_R<50 && CSLeft_G>240 && CSLeft_B>240) || (CSRight_R<50 && CSRight_G>240 && CSRight_B>240)) //BLUE
  {
    return 3;
  }
  if((CSLeft_R<10 && CSLeft_G>140 && CSLeft_B>240) || (CSRight_R<10 && CSRight_G>140 && CSRight_B>240)) //BLUE DOUBLE ZONE
  {
    return 4;
  }
  if((CSLeft_R<60 && CSLeft_G<60 && CSLeft_B<60) || (CSRight_R<60 && CSRight_G<60 && CSRight_B<60)) //BLACK
  {
    return 5;
  }
  if((CSLeft_R>200 && CSLeft_G>200 && CSLeft_B<10) || (CSRight_R>200 && CSRight_G>200 && CSRight_B<10)) //YELLOW
  {
    return 6;
  }
  if((CSLeft_R>200 && CSLeft_G>150 && CSLeft_B<10) || (CSRight_R>200 && CSRight_G>150 && CSRight_B<10)) //ORANGE
  {
    return 7;
  }
}

int calcularPid(float setPoint, float actual, float kd, float kp)
{
  	float error, prevError = 0, pid, p, d;
    error = actual - setPoint;
  	p = error * kp;
  	d = (error - prevError) * kd;
  	prevError = error;
  	pid = p+d;
  	return pid;
}

void proof(){
  if(turn(1)==1)
    fwd(5);
}
