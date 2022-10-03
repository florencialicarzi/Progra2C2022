#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "TDA_Pila.h"

//PILA ESTATICA
void crearPila(Pila* pp)
{
    pp->tope=0;
}

bool apilar(Pila* pp,const void* elem, size_t tamElem)
{
    //valor de tope, verifico si hay lugar
    if(tamElem+sizeof(size_t)>TAM_PILA- pp->tope) //"tope como si guardara el tamaño, rari"
        return false;
    //copio el elemento
    memcpy(pp->vPila+pp->tope,elem,tamElem);
    pp->tope+=tamElem;
    //copio el tamaño del elemento
    *(size_t*)(pp->vPila+pp->tope)=tamElem;
    pp->tope+=sizeof(size_t);
    return true;
}

bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope==0)
        return false;

    //leo el tamaño del ultimo elemento;
    pp->tope-=sizeof(size_t);
    size_t tamElemApilado= *(size_t*)(pp->vPila+pp->tope);
    //Retrocedo el puntero hasta el principio del elemento y copio
    pp->tope-=tamElemApilado;
    memcpy(elem,pp->vPila+pp->tope,min(tamElem,tamElemApilado)); //minimo de tamaño del elemento dispo
    return true;
}

bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope==0)
        return false;
    unsigned tope= pp->tope;
    tope-=sizeof(size_t);
    size_t tamElemApilado=*(size_t*)(pp->vPila+tope);
    tope-=tamElemApilado;
    memcpy(elem,pp->vPila+tope,min(tamElem,tamElemApilado));
    return true;
}

bool pilaLlena(const Pila* pp, size_t tamElem)
{
    return(tamElem+sizeof(size_t)>TAM_PILA-pp->tope);
}

bool pilaVacia(const Pila* pp)
{
    return (pp->tope==0);
}


void vaciarPila(Pila* pp)
{
    pp->tope=0;
}

