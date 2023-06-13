#ifndef VECTORENTEROS_H_INCLUDED
#define VECTORENTEROS_H_INCLUDED

void mostrarVectorEnteros(int *vec, int ce);
void compararVectores(int *vec1, int *vec2, int ce);
void insertarVecPos(int *vec, int elem ,int pos, int *ce,int tam);
void insertarVecOrd(int *vec, int elem, int *ce, int tam);
void eliminarEnVectorPos(int *vec,int pos, int *ce);
void eliminarPrimerAparicionElem(int *vec, int elem ,int *ce);
void eliminarAparicionesElem(int *vec, int elem ,int *ce);

#endif // VECTORENTEROS_H_INCLUDED
