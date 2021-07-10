/*
Estructura de una lista
*/
#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#ifndef LISTA_h
#define LISTA_h 1
typedef struct{
    Nodo *first;
}Lista;
Lista *crearLista();
void addLastLista(Lista *lista, int elemento);
void addLista(Lista *lista, int elemento, int posicion);
int isInLista(Lista *lista, int valor);
void imprimirLista(Lista *lista);

#endif

