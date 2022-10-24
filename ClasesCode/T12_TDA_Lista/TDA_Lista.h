#ifndef TDA_LISTA_H_INCLUDED
#define TDA_LISTA_H_INCLUDED

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo sig;

}Nodo;

typedef Nodo* Lista;

typedef int(*Cmp)(const void*, const void*);
typedef void(*Actualizar)(void*, const void*); //(elem del nodo(act), elem del param(leo))

int comparar(const void* dato1, const void* dato2);
Lista* buscarMenor(Lista* aux, Lista* menor, Cmp cmp);
void ordenarListaSeleccion(Lista* pl, Cmp cmp);

#endif // TDA_LISTA_H_INCLUDED
