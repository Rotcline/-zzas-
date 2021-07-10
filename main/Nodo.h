/*
Estructura de un nodo de una lista
*/
#include <stdio.h>
#include <stdlib.h>
#ifndef NODO_h
#define NODO_h 1
typedef struct{
    int valor;//Valor que se guarda en el nodo
    struct Nodo *next;//puntero al siguiente
}Nodo;
void *createNodo(int valor);
int getValorNodo(Nodo *nodo);
void setValorNodo(Nodo *nodo, int valor);
Nodo *getNextNodo(Nodo *nodo);
void *setNextNodo(Nodo *nodo, Nodo *next);
#endif
