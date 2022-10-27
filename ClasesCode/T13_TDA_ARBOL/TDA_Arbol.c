#include "TDA_Arbol.h"

void crearArbol(Arbol* pa)
{
    *pa=NULL;
}

bool buscarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    if(!*pa)
        return false;

    int comp= cmp(elem, (*pa)->elem);

    if(comp == 0)
    {
        memcpy(elem, (*pa)->elem), min(tamElem, (*pa)->tamElem));
        return true;
    }

    if(comp < 0)
        return buscarEnArbol(&(*pa)->hIzq, elem, tamElem, cmp);
    else
        return buscarEnArbol(&(*pa)->hDer, elem, tamElem, cmp);
}
