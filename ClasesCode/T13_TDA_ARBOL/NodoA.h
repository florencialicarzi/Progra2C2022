#ifndef NODOA_H_INCLUDED
#define NODOA_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

typedef struct SNodoA
{
    void* elem;
    size_t tamElem;
    struct SNodoA* hIzq;
    struct SNodoA* hDer;

}NodoA;

#endif // NODOA_H_INCLUDED
