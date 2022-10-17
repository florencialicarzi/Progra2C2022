#ifndef TDA_PILA_H_INCLUDED
#define TDA_PILA_H_INCLUDED

#include <stdbool.h>

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define TAM_PILA 42

 #ifdef PILA_EST
    #include TDAPilaEstatica.h
   #endif
   #ifdef PILA_DIN
    #include TDAPilaDinamica.h
   #endif


void crearPila(Pila* pp);
bool apilar(Pila* pp,const void* elem, size_t tamElem); //Bool que me diga si pudo apilar
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pp);
bool pilaLlena(const Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);


#endif // TDA_PILA_H_INCLUDED
