#ifndef TDA_PILA_ESTATICA_H_INCLUDED
#define TDA_PILA_ESTATICA_H_INCLUDED
#define min(x,y) (((x) < (y)) ? (x) : (y))

#define TAM_PILA 42
#include <stdbool.h>

typedef struct
{
    char vPila[TAM_PILA];
    unsigned tope;

}Pila;

void crearPila(Pila* pila);
bool apilar(Pila* pila, const void* Elem, size_t tamElem);
bool desapilar(Pila* pila, void* Elem, size_t tamElem);
bool verTopeDePila(const Pila* pila, void* Elem, size_t tamElem);
bool pilaVacia(const Pila* pila);
bool pilaLlena(const Pila* pila, size_t tamElem);
void vaciarPila(Pila* pila);
#endif // TDA_PILA_ESTATICA_H_INCLUDED
