#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>

#define TAM 7


typedef enum
{
    ERROR, INSERTADO
} booleano;


int llenarVector(int *vec);
booleano insEnVector(int *vec, int pos, int elem, const int cantElem);
booleano insEnVecOrdenado(int *vec, int elem, const int cantElem);

#endif // VECTORES_H_INCLUDED
