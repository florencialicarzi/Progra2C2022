#ifndef TDA_PILA_DINAMICA_H_INCLUDED
#define TDA_PILA_DINAMICA_H_INCLUDED

#include <stdbool.h>

#define min(x,y) ((x)<(y))? (x):(y);

typedef struct SNodo
{
    void elem;
    size_t tamElem;
    SNodo* sig;
}Nodo;

void crearPila(Pila* pp);
bool apilar(Pila* pp, void* elem, size_t tamElem);
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(const Pila* pp, void* elem, size_t tamElem);
bool pilaLlena(const Pila* pp, size_t tamElem);
bool pilaVacia(const Pila* pp);
void vaciarPila(Pila* pp);


#endif // TDA_PILA_DINAMICA_H_INCLUDED
