#include "C:\3.14159zzas\3.14159zzas\main\CoSpaceRobot.h"
#include "C:\3.14159zzas\3.14159zzas\main\ai.h"
#define LEFT 0
#define RIGHT 1
#define PICK 0
#define DROP 1
#define FWDL 2
#define FWDR 3
struct SColor SensorDer;
struct SColor SensorIzq;
struct Motor LMotor;
struct Motor RMotor;
float calcularPid(float setPoint, float actual, float kd, float kp);
int boolTurn=0;
int gradesTo;
int boolAvanzaZ=0;



int initRobot(){
  LMotor.side = LEFT;
  RMotor.side = RIGHT;
  SensorDer.r = &CSRight_R;
  SensorDer.g = &CSRight_G;
  SensorDer.b = &CSRight_B;
  SensorIzq.r = &CSLeft_R;
  SensorIzq.g = &CSLeft_G;
  SensorIzq.b = &CSLeft_B;
  return 1;
}


int valueSColor(int side){
  switch (side) {
    case LEFT:
      return detectColor(&SensorIzq);
    break;
    case RIGHT:
      return detectColor(&SensorDer);
    break;
  }

}



int avanzaRobot(int speed){
  asignarMotor(&LMotor, speed);
  asignarMotor(&RMotor, speed);
  return 1;
}

int turnRobot(int setPoint){
  int auxp = setPoint+5, auxn = setPoint-5;
  if(auxn<0){
    auxn+=360;
  }
  if(auxp>360){
    auxp-=360;
  }
  if(gradosCompass()<=auxp && gradosCompass()>=auxn){
      return 1;
  }
  if(setPoint<180){
    if(gradosCompass()<=setPoint+180 && gradosCompass()>setPoint){
        asignarMotor(&RMotor, -calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
        asignarMotor(&LMotor, calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
      }
      else{
      asignarMotor(&RMotor, calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
      asignarMotor(&LMotor, -calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
      }
  }
  if(setPoint>=180){
    if(gradosCompass()>=setPoint+180-360 && gradosCompass()<setPoint){
      asignarMotor(&RMotor, calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
      asignarMotor(&LMotor, -calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
    }
    else{
      asignarMotor(&RMotor, -calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
      asignarMotor(&LMotor, calcularPid(setPoint, gradosCompass(), 2.5, 2.5));
    }
  }
}

int turnRRobot(int grados){
  if(boolTurn == 0){
    gradesTo = gradosCompass() + grados;
    if(gradesTo>360)
      gradesTo-=360;
    if(gradesTo<0)
      gradesTo+=360;
    boolTurn = 1;
  }
  turnRobot(gradesTo);
  if(gradosCompass()<=gradesTo+20 && gradosCompass()>=gradesTo-20)
  {
    boolTurn = 0;
    return 1;
  }

}

int turnReverseRobot(int setPoint){
  int auxp = setPoint+5, auxn = setPoint-5;
  if(auxn>0){
    auxn+=360;
  }
  if(gradosCompass()<=auxp && gradosCompass()>=auxn){
      return 1;
  }
  if(setPoint<180){
    if(gradosCompass()<=setPoint+180 && gradosCompass()>setPoint){
        asignarMotor(&RMotor, -calcularPid(setPoint, gradosCompass(), 2, 2.5));
        asignarMotor(&LMotor, 0);
      }
      else{
      asignarMotor(&RMotor, 0);
      asignarMotor(&LMotor, -calcularPid(setPoint, gradosCompass(), 2, 2.5));
      }
  }
  if(setPoint>=180){
    if(gradosCompass()>=setPoint+180-360 && gradosCompass()<setPoint){
      asignarMotor(&RMotor, 0);
      asignarMotor(&LMotor, -calcularPid(setPoint, gradosCompass(), 2, 2.5));
    }
    else{
      asignarMotor(&RMotor, -calcularPid(setPoint, gradosCompass(), 2, 2.5));
      asignarMotor(&LMotor, 0);
    }
  }
}

int turnReverseRRobot(int grados){
  if(boolTurn == 0){
    gradesTo = gradosCompass() + grados;
    if(gradesTo>360)
      gradesTo+=360;
    boolTurn = 1;
  }
  turnReverseRobot(gradesTo);
  if(gradosCompass()<=gradesTo+20 && gradosCompass()>=gradesTo-20)
    boolTurn = 0;
}

int verifyDuration(){
  if(Duration>0){
    Duration--;
    return 1;
  }
  else{
    Duration=49;
    return 1;
  }
}

int currentAction(){
  switch (CurAction) {
    case DROP:
      avanzaRobot(0);
      LED_1=2;
      MyState=0;
      if(Duration<4){
        avanzaRobot(-3);
      }
      if(Duration == 1) {
        LoadedObjects = 0;
        CurAction=-1;
      }
    break;
    case PICK:
      avanzaRobot(0);
      LED_1=1;
      MyState=0;
      if(Duration == 1) {
        LoadedObjects++;
        CurAction=-1;
      }
      if(Duration < 6)
      {
          avanzaRobot(2);
      }
    break;
  }
}


int depositarRobot(/*int time*/){
  if(LoadedObjects>0){
    CurAction=DROP;
    verifyDuration();
    currentAction();
  }
}


int recogeRobot(/*int time*/){
  if(LoadedObjects<6){
  CurAction=PICK;
  verifyDuration();
  currentAction();
  }
}


float calcularPid(float setPoint, float actual, float kd, float kp)
{
    actual-=setPoint;
    setPoint-=setPoint;
    if(actual<0)
      actual+=360;
    if(actual>180)
      setPoint = 360;
  	float error, prevError = 0, pid, p, d;
    error = actual - setPoint;
  	p = error * kp;
  	d = (error - prevError) * kd;
  	prevError = error;
  	pid = (p+d)*5/360;
    if(pid<0)
  	 return -pid;
    else
      return pid;
}
