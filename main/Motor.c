#include "C:\3.14159zzas\3.14159zzas\main\Motor.h"
#define LEFT 0
#define RIGHT 1


void asignarMotor(struct Motor *motor,int speed){
  switch (motor->side) {
    case LEFT:
      WheelLeft=speed;
    break;
    case RIGHT:
      WheelRight=speed;
    break;
  }
}
