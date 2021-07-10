#include "Nodo.h"
void *createNodo(int valor){
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo-> valor = valor;
    nuevoNodo-> next = NULL;
    return nuevoNodo;
}
int getValorNodo(Nodo *nodo){
    return nodo->valor;
}
void setValorNodo(Nodo *nodo, int valor){
    nodo->valor = valor;
}
Nodo *getNextNodo(Nodo *nodo){
    return nodo->next;
}
void *setNextNodo(Nodo *nodo, Nodo *next){
    nodo->next = next;
}

