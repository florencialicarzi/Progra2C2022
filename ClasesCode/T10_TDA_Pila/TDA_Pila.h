#ifndef TDA_PILA_H_INCLUDED
#define TDA_PILA_H_INCLUDED

#include <stdbool.h>

typedef int Pila;

void crearPila(Pila* pila);
bool apilar(Pila* pila, void* elem, size_t tamElem); //Bool que me diga si pudo apilar
bool desapilar(Pila* pila, void* elem, size_t tamElem);
bool verTopeDePila(const Pila* pila, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pila);
bool pilaLlena(const Pila* pila);
void vaciarPila(Pila* pila);

char* sumar(const char* num1, const char* num2);
bool apilarCeros(Pila* pila, int cantCeros);
bool apilarNumero(Pila* pila, const char* num);
bool desapilarNumero(char* num, Pila* pilaSuma);
#endif // TDA_PILA_H_INCLUDED
