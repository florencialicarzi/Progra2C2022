#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDA_Pila_Estatica.h"

void crearPila(Pila* pp)
{
    pp->tope=0;
}
bool apilar(Pila* pp, const void* elem, size_t tamElem)
{
    //primero me fijo que haya espacio suficiente
    if(TAM_PILA - pp->tope< tamElem + sizeof(size_t)) //C
        return false;
    //copio el elemento y aumento el tope
    memcpy(pp->vPila + pp->tope, elem, tamElem);
    pp->tope+=tamElem;
    //copio el tamElem y aumento el tope
    *(size_t*)(pp->vPila+pp->tope)=tamElem;
    pp->tope+= sizeof(size_t);
    return true;
}

bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope==0)
        return false;
    //corro el puntero hacia atras y leo el tamElemApilado
    pp->tope-=sizeof(size_t);
    size_t tamElemApilado= *(size_t*)(pp->vPila+pp->tope);
    //corro el puntero con tamElemApilado y leo el elemento
    pp->tope-=tamElemApilado;
    memcpy(elem, pp->vPila+pp->tope,min(tamElem, tamElemApilado));
    return true;
}
bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope==0)
        return false;
    unsigned tope = pp->tope;
    tope-=sizeof(size_t);
    size_t tamElemApilado= *(size_t*)(pp->vPila+tope);
    tope-=tamElemApilado;
    memcpy(elem, pp->vPila+tope, min(tamElem,tamElemApilado));
    return true;
}

bool pilaVacia(const Pila* pp)
{
    return pp->tope==0;
}

bool pilaLlena(const Pila* pp, size_t tamElem)
{
    //recordar que tengo que guardar el tamElem + tam Size_t
    return(TAM_PILA-(pp->tope)<tamElem+sizeof(size_t));
}

void vaciarPila(Pila* pp)
{
    pp->tope=0;
}
