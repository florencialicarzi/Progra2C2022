#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo.h"

Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(nue == NULL || elemNodo == NULL)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem= elemNodo;
    nue->tamElem= tamElem;
    nue->sig = NULL;
}

void destruirNodo(Nodo* nae,void* elem,size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}

