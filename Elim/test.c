#include <stdio.h>

void funcion1();
void funcion2();
void funcion3();
void funcion4();
int index;
void (*indicador)(int);
int main() {
  while(1){
    scanf("%d",&index);
    switch(index){
      case 1:
        indicador=funcion1;
      break;
      case 2:
        indicador=funcion2;
      break;
      case 3:
        indicador=funcion3;
      break;
      case 4:
        indicador=funcion4;
      break;
      default:
        printf("JAJA NO aqui no va a estar la pelicula que no es canon en pixar ;)\n");
      break;
    }
    indicador(index);
  }
  return 0;
}

void funcion1(int i){
  printf("Klaus %d\n", i);
}
void funcion2(int i){
  printf("Como entrenar a tu dragon %d\n", i);
}
void funcion3(int i){
  printf("Perdi mi Cuerpo %d\n", i);
}
void funcion4(int i){
  printf("El maravilloso Señor Link %d\n", i);
}
