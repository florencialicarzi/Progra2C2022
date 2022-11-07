#ifndef TDA_ARBOL_H_INCLUDED
#define TDA_ARBOL_H_INCLUDED

#include "stdio.h"
#include "stdbool.h"
#include "NodoA.h"
#include "ArbolImplDinamica.h"
//typedef NodoA* Arbol; esta en el include de arriba

#define TODO_OK 0
#define ERROR 1
#define SIN_MEM 2
#define DUPLICADO 3

#define min(x,y) (((x)>(y))? (x) : (y))

typedef int(*Cmp)(const void*, const void*);
typedef void(*Accion)(void*,void*);
typedef void(*Actualizar)(void*, const void*);

void crearArbol(Arbol* pa);
void vaciarArbol(Arbol* pa);
bool esArbolVacio(const Arbol* pa);
bool buscarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
int insertarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
void recorrerArbolPre(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEn(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPos(const Arbol* pa, Accion accion, void* datosAccion);
int contarNodosArbol(const Arbol* pa);
int contarHojasArbol(const Arbol* pa);
int contarNoHojasArbol(const Arbol* pa);
int contarNodosNivelArbol(const Arbol* pa, int nivel);
int alturaArbol(const Arbol* pa);
int podarArbol(const Arbol* pa, int nivel);
bool esArbolCompleto(const Arbol* pa);
bool esArbolBalanceado(const Arbol* pa);
bool esArbolAVL(const Arbol* pa);

#endif // TDA_ARBOL_H_INCLUDED
