#define PILA_DIN
#include "TDA_Pila.h"

void crearPila(Pila* pp)
{
    //le asigno null a lo que apunta el puntero de pila (Dibujo: FC08)
    *pp = NULL;
}

bool apilar(Pila* pp,const void* elem, size_t tamElem)
{
//Reservo memoria
  Nodo* nue= malloc(sizeof(Nodo));
  void* elemNodo= malloc(tamElem);

  if(nue==NULL || elemNodo== NULL)
  {
      free(nue);
      free(elemNodo);
      return false;
  }

  memcpy(elemNodo, elem, tamElem);
  nue->elem = elemNodo;
  nue->tamElem = tamElem

  nue->sig= *pp;
  *pp = nue;

  return true;

}

bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
    {
        return false;
    }
    Nodo* nae= *pp;
    *pp = nae-> sig;

    memcpy(elem, nae->elem, min(nae->tamElem, tamElem));

    free(nae->elem);
    free(nae);

    return true;
}

bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return false;
    Nodo* tope= *pp;
    memcpy(elem, tope->elem, min(tamElem, tope->tamElem));
}

bool pilaVacia(const Pila* pp)
{
    return !(*pp)
}
bool pilaLlena(const Pila* pp, size_t tamElem)
{
    //Rari, solo reserva memoria para ver si alcanza
    //pero la libera despues para que no robe.
    //solo pruebo si hay lugar

    void* nodo = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);

    free(nodo);
    free(elem);

    //lo que dejo malloc en el puntero sigue estando
    //aunque se haya llamado a free

    return !nodo || !elem;
}
void vaciarPila(Pila* pp)
{
    Nodo* nae;

    while(*pp) //mientras *pp no sea nulo
    {
        nae=*pp; //las de desapilar
        *pp= nae->sig; //Desapila hasta llegar nae->sig=NULL
        free(nae->elem);
        free(nae);
    }
}

