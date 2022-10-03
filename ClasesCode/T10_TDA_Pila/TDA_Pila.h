#ifndef TDA_PILA_H_INCLUDED
#define TDA_PILA_H_INCLUDED
#define min(x,y) (((x) < (y)) ? (x) : (y))
#include <stdbool.h>
#define TAM_PILA 42
/* #ifdef PILA_EST
    #include TDAPilaEstatica.h
   #endif
   #ifdef PILA_DIN
    #include TDAPilaDinamica.h
   #endif
*/

//pila estatica
typedef struct
{
    char vPila[TAM_PILA];
    unsigned tope;
}Pila;


void crearPila(Pila* pila);
bool apilar(Pila* pila,const void* elem, size_t tamElem); //Bool que me diga si pudo apilar
bool desapilar(Pila* pila, void* elem, size_t tamElem);
bool verTopeDePila(const Pila* pila, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pila);
bool pilaLlena(const Pila* pila, size_t tamElem);
void vaciarPila(Pila* pila);

char* sumar(const char* num1, const char* num2);
bool apilarCeros(Pila* pila, int cantCeros);
bool apilarNumero(Pila* pila, const char* num);
bool desapilarNumero(char* num, Pila* pilaSuma);
#endif // TDA_PILA_H_INCLUDED
