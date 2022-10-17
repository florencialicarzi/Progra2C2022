#include <stdlib.h>
#include "TDA_Pila_Dinamica.h"

void crearPila(Pila* pp)
{
    *pp=NULL;
}
bool apilar(Pila* pp, void* elem, size_t tamElem)
{
    Nodo* nue= malloc(sizeof(Nodo));
    void* elemNodo= malloc(tamElem);

    if(!nue||!elemNodo)
    {
        return false;
    }

    memcpy(elemNodo, elem, tamElem);
    nue->elem= elemNodo;
    nue->tamElem = tamElem;
    nue->sig = *pp;
    *pp= nue;

    return true;
}
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(const Pila* pp, void* elem, size_t tamElem);
bool pilaLlena(const Pila* pp, size_t tamElem);
bool pilaVacia(const Pila* pp);
void vaciarPila(Pila* pp);
