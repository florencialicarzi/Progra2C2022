#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#define min(x,y) (((x) < (y)) ? (x) : (y))

#include <stdbool.h>

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
}Nodo;



Nodo* crearNodo(const void*, size_t);
void destruirNodo(Nodo* nae,void* elem,size_t tamElem);

#endif // NODO_H_INCLUDED
