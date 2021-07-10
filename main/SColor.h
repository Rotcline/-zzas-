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
#ifndef SCOLOR_H
#define SCOLOR_H
#include "C:\3.14159zzas\3.14159zzas\main\ai.h"
//lado = 0 derecha
//lado = 1 izquierda
typedef struct SColor{ /*Crea la estructura Sensor de Color.*/
    int *r; /*Este puntero y los 3 de abajo son para definir a que sensor nos referimos.*/
    int *g;
    int *b;
};

int detectColor(struct SColor *scolor); /*Retorna el color que ve el Sensor que otorgas como argumento.*/
 /*
 Rojo     = 0 Objeto de valor 10.
 Cyan     = 1 Objeto de valor 15.
 Negro    = 2 Objeto de valor 20.
 Naranja  = 3 Zona de deposito.
 Amarillo = 4 Alerta de trampa. !Te quita todos los objetos de la mochila!
 Gris     = 5 Zona que disminuye velocidad.
 Azul     = 6 Zona de doble puntaje.
 */


#endif
