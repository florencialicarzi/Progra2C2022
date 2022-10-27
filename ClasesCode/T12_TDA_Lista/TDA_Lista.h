#ifndef TDA_LISTA_H_INCLUDED
#define TDA_LISTA_H_INCLUDED

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2
#define LISTA_VACIA 3
#define NO_EXISTE 4

#define min(x,y) (((x) < (y)) ? (x) : (y))

#include <stdbool.h>

typedef int(*Cmp)(const void*, const void*);
typedef void(*Actualizar)(void*, const void*); //(elem del nodo(act), elem del param(leo))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;

}Nodo;

typedef Nodo* Lista;

//P R I M I T I V A S
void crearLista();

int insertarEnListaOrdSinDup(Lista*, const void*, size_t , Cmp , Actualizar );
int insertarListaOrdDup(Lista*, const void*, size_t , Cmp);
//int insertarListaDesordSinDup(Lista*, const void*, size_t , Cmp , Actualizar );
//int insertarListaDesordDup(Lista*, const void*, size_t , Cmp , Actualizar );
//int insertarEnPosSinDup(Lista*,int,const void*, size_t, Cmp, Actualizar);
//int insertarEnPosDup(Lista*,int,const void*, size_t, Cmp, Actualizar);
//int insertarInicio(Lista*, const void*, size_t);
//int insertarFinal(Lista*, const void*, size_t);

int eliminarDeListaOrdXValor(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
//int eliminarDeListaEnPos(Lista* pl,int pos ,void* elem, size_t tamElem, Cmp cmp);
//int eliminarPri(Lista* pl, void*elem, size_t tamElem);
//int eliminarUlt(Lista* pl, void*elem, size_t tamElem);

bool buscarEnListaOrd(Lista*, void*, size_t, Cmp cmp);
//void buscarEnListaDesord(Lista*, void*, size_t);

void ordenarListaInsercion(Lista* pl, Cmp cmp);
void ordenarListaSeleccion(Lista* pl, Cmp cmp);

bool listaLlena(Lista* pl, size_t);
bool listaVacia(Lista* pl);

void vaciarLista(Lista *pl);

//void mostrarLista(Lista* pl, void (*mostrar)(const void* elem));
//void mostrarEntero(const void* elem);

//FUNCIONES
int comparar(const void* dato1, const void* dato2);
Lista* buscarMenor(Lista* aux, Lista* menor, Cmp cmp);

#endif // TDA_LISTA_H_INCLUDED

