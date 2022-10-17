#ifndef TDA_COLA_H_INCLUDED
#define TDA_COLA_H_INCLUDED

#include <stdbool.h>

#ifdef TDA_COLA_EST
    #include "TDA_Cola_Estatica.h"
#endif

#ifdef TDA_COLA_DIN
    //#include
#endif


void crearCola(Cola*pc);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool verTopeDeCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc);
void vaciarCola(Cola* pc);

#endif // TDA_COLA_H_INCLUDED
