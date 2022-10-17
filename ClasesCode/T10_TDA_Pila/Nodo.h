#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <stdlib.h>

typedef struct SNodo
{
    void* elem;
    size_t tamElem;
    struct SNodo* sig;

}Nodo;


#endif // NODO_H_INCLUDED
