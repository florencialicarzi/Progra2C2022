#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_Lista.h"


//CREAR LISTA
void crearLista(Lista* pl)
{
    *pl= NULL;
}

//INSERTAR EN LISTA

int insertarEnListaOrdSinDup(Lista *pl, const void*elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    while(*pl&&(cmp(elem,(*pl)->elem))>0) //cuidao segmentation fault
        pl=&(*pl)->sig;

    if(*pl&&cmp(elem,(*pl)->elem)==0)
    {
        actualizar((*pl)->elem, elem);
        return DUPLICADO;
    }

     Nodo* nue= malloc(sizeof(Nodo));
    void* elemNodo= malloc(tamElem);

    if(nue == NULL || elemNodo==NULL)
    {
        free(elemNodo);
        free(nue);
        return SIN_MEM;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem= elemNodo;
    nue->tamElem= tamElem;
    nue->sig= *pl;
    *pl=nue;

    return TODO_OK;
}

int insertarListaOrdDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl&&(cmp(elem,(*pl)->elem))>0)
        pl= &(*pl)->sig;

    Nodo* nue= malloc(sizeof(Nodo));
    void* elemNodo= malloc(tamElem);

    if(nue == NULL || elemNodo==NULL)
    {
        free(elemNodo);
        free(nue);
        return SIN_MEM;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem= elemNodo;
    nue->tamElem= tamElem;
    nue->sig= *pl;
    *pl=nue;

    return TODO_OK;
}

//int insertarListaDesordSinDup(Lista*, const void*, size_t , Cmp , Actualizar )
//int insertarListaDesordDup(Lista*, const void*, size_t , Cmp , Actualizar );
//int insertarEnPosSinDup(Lista*,int,const void*, size_t, Cmp, Actualizar);
//int insertarEnPosDup(Lista*,int,const void*, size_t, Cmp, Actualizar);
//int insertarInicio(Lista*, const void*, size_t);
//int insertarFinal(Lista*, const void*, size_t);


//ELIMINAR DE LISTA
int eliminarDeListaOrdXValor(Lista* pl, void* elem, size_t tamElem, Cmp cmp) //elem me trae el dato pero ahi devuelvo el nodo
{
    if(!*pl)
        return LISTA_VACIA;

    while(*pl&& cmp(elem,(*pl)->elem)>0)
        pl = &((*pl)->sig);

    if(!*pl || !(cmp(elem,(*pl)->elem)<0))
        return NO_EXISTE;

    Nodo* nae = *pl;
    *pl= nae->sig;

    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
    return TODO_OK;
}
//int eliminarDeListaEnPos(Lista* pl,int pos ,void* elem, size_t tamElem, Cmp cmp);
//int eliminarPri(Lista* pl, void*elem, size_t tamElem);
//int eliminarUlt(Lista* pl, void*elem, size_t tamElem);

//BUSCAR EN LISTA
bool buscarEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(!*pl || cmp(elem, (*pl)->elem) != 0)
        return false;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return true;
}
//void buscarEnListaDesord(Lista*, void*, size_t);

//ORDENAR LISTA
void ordenarListaSeleccion(Lista* pl, Cmp cmp)
{

    Lista* menor = pl;
    Lista* aux = pl;

    if(*pl == NULL)
        return;


    while((*pl)->sig) // Mientras haya siguiente, si hay uno solo esta ordenada.
    {

        menor = buscarMenor(aux, menor, cmp);

        Nodo* pri = *menor;

        *menor = pri->sig;

        pri->sig = *pl;

        *pl = pri;

        pl = &(*pl)->sig;

        menor = pl;
        aux =pl;

    }
}

void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista lOrd= NULL;
    Lista* plOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo=*pl;
        *pl= nodo->sig;
        plOrd= &(*plOrd);

        while(*plOrd && cmp(nodo->elem, (*plOrd)->elem) >0)
              plOrd = &(*plOrd)->sig;

        nodo->sig = *plOrd;
        *plOrd=nodo;
    }

    *pl=lOrd;
}

//LISTA LLENA/VACIA
bool listaLlena(Lista* pl, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    free(elemNodo);
    free(nue);

    return !nue || !elemNodo;
}

bool listaVacia(Lista* pl)
{
    return *pl == NULL;
}

//VACIAR LISTA
void vaciarLista(Lista* pl)
{
    Nodo* nae;

    while(*pl)
    {
        nae = *pl;

        *pl = nae->sig;

        free(nae->elem);
        free(nae);
    }
}

//MOSTRAR LISTA
//void mostrarLista(Lista* pl, void (*mostrar)(const void* elem));
//void mostrarEntero(const void* elem);



//FUNCIONES AUXULIARES
int comparar(const void* dato1, const void* dato2)
{
    return *(int*)dato1 - *(int*)dato2;
}

Lista* buscarMenor(Lista* aux, Lista* menor, Cmp cmp)
{

    while((*aux)->sig) // Mientras haya siguiente, si hay uno solo esta ordenada.
    {

        if(cmp((*menor)->elem, (*aux)->sig->elem) > 0)
            menor = &(*aux)->sig;

        aux = &(*aux)->sig;

    }

    printf("\nMenor: %d", *(int*)(*menor)->elem);
    return menor;
}



