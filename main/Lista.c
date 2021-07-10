#include "Lista.h"

Lista *createLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->first = NULL;
}
void addLastLista(Lista *lista, int elemento){
    if(lista->first == NULL){
        lista->first = createNodo(elemento);
        return;
    }
    Nodo *listalast = lista->first;
    while(listalast->next != NULL){
        listalast = listalast->next;
    }
    Nodo *nuevo = createNodo(elemento);
    listalast->next = nuevo;
}
void addLista(Lista *lista, int elemento, int posicion){
    int i;
    if(posicion < 0)
        return;
    if(lista->first == NULL){
        lista->first = createNodo(elemento);
        return;
    }
    if(posicion == 0){
        Nodo *nuevo = createNodo(elemento);
        nuevo->next = lista->first;
        lista->first = nuevo;
        return;
    }
    Nodo *listalast = lista->first;
    for(i = 0; i < posicion-1; i++){
        if(listalast->next != NULL){
            listalast = listalast->next;
        }
    }
    Nodo *nuevo = createNodo(elemento);
    nuevo->next = listalast->next;
    listalast->next = nuevo;
}
int isInLista(Lista *lista, int valor){
    Nodo *listalast = lista->first;
    while(listalast->next != NULL){
        if(listalast->valor ==valor)
            return 1;
        listalast = listalast->next;
    }
    return 0;
}
void imprimirLista(Lista *lista){
    Nodo *listalast = lista->first;
    while(listalast != NULL){
        printf("%i ", listalast->valor);
        listalast = listalast->next;
    }
    printf("\n");
}
