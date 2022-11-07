#include "TDA_Arbol.h"
#include "string.h"

//prototipos de Nodos:
Arbol* buscarNodoA(Arbol* pa, void* elem, Cmp cmp);

void eliminarNodoA(Arbol* pnae);

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
        memcpy(elem, (*pa)->elem, min(tamElem, (*pa)->tamElem));
        return true;
    }

    if(comp < 0)
        return buscarEnArbol(&(*pa)->hIzq, elem, tamElem, cmp);
    else
        return buscarEnArbol(&(*pa)->hDer, elem, tamElem, cmp);
}

int insertarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    if(!*pa)
    {
        *pa = crearNodoA(elem, tamElem);

        if(!*pa)
            return SIN_MEM;

        return TODO_OK;
    }

    int comp = cmp(elem,(*pa)->elem);

    if(comp==0)
    {
        actualizar((*pa)->elem, elem);
        return DUPLICADO;
    }

    return insertarEnArbol(comp<0? &(*pa)->hIzq : &(*pa)->hDer, elem, tamElem, cmp, actualizar);

}

bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp )
{
    Arbol* pnae = buscarNodoA(pa,elem,cmp);//no es primitiva

    if(!pnae)
        return false;

    memcpy(elem, (*pnae)->elem, min(tamElem, (*pnae)->tamElem));
    free((*pnae)->elem);

    eliminarNodoA(pnae);

    return true;
}

int alturaArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;
   int hi = alturaArbol(&(*pa)->hIzq);
   int hd = alturaArbol(&(*pa)->hDer);

   return (hi< hd ? hi: hd) +1;
}

//no es primitivaa:
Arbol* buscarNodoA(Arbol* pa, void* elem, Cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp= cmp(elem, (*pa)->elem);

    if(comp == 0)
    {
        return pa;
    }

    return buscarNodoA(comp<0 ? &(*pa)->hIzq: &(*pa)->hDer, elem, cmp);
}

void eliminarNodoA(Arbol* pnae)
{
    //si es hoja
    if(!(*pnae)->hIzq && !(*pnae)->hDer)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }

    //si no es hoja busca reemplazo del de mayor altura
    int hi = alturaArbol(&(*pnae)->hIzq);
    int hd = alturaArbol(&(*pnae)->hDer);

    Arbol* pnreempl = hi>= hd? nodoMayorA(&(*pnae)->hIzq) : nodoMenorA(&(*pnae)->hDer);

    (*pnae)->elem = (*pnreempl)->elem;
    (*pnae)->tamElem = (*pnreempl)->tamElem;

    eliminarNodoA(pnreempl);
}

Arbol* nodoMenorA(Arbol* pa)
{
    while((*pa)->hIzq)
        pa = &(*pa)->hIzq;

    return pa;
}

Arbol* nodoMayorA(Arbol* pa)
{
    while((*pa)->hDer)
        pa = &(*pa)->hDer;

    return pa;
}
