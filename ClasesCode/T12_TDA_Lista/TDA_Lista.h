#ifndef TDA_LISTA_H_INCLUDED
#define TDA_LISTA_H_INCLUDED

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2

typedef int(*Cmp)(const void*, const void*);
typedef void(*Actualizar)(void*, const void*); //(elem del nodo(act), elem del param(leo))

#endif // TDA_LISTA_H_INCLUDED
