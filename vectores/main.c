#include <stdio.h>
#include <stdlib.h>

#include "utiles.h"
#include "vectorEnteros.h"

#define TAM 10

int main()
{
//--VECTORES
    int vec1[TAM] = {22,2,22,4,5,6,22,8,22};
    //int vec2[TAM] = {7,6,3,5};
    int ce=9; //ce2=4;

    printf("Vector original:");
    mostrarVectorEnteros(vec1, ce);

//----------------------------------------------//
/*    puts("COMPARAR VECTORES:");

    compararVectores(vec1, vec2, 4);
    puts("");
*/
//--------------------------------------------/
/*
    puts("\nINSERTAR EN VECTOR X POSICION:");

    insertarVecPos(vec1, 22, 10, &ce,TAM); //vector, elem, pos, ce, tam

*/
//--------------------------------------------/
    /*puts("\nINSERTAR EN ORDEN");

    insertarVecOrd(vec1,100,&ce,TAM);

*/
//--------------------------------------------/
/*    puts("\nELIMINAR EN POSICION");
    eliminarEnVectorPos(vec1,1,&ce);
*/
//--------------------------------------------/
/*    puts("\nELIMINAR PRIMER APARACION DE ELEM");
    eliminarPrimerAparicionElem(vec1,5,&ce);
*/
//--------------------------------------------/
    puts("\nELIMINAR APARICIONES DE ELEM");
    eliminarAparicionesElem(vec1,22,&ce);

    mostrarVectorEnteros(vec1,ce);
    return 0;
}

/*
(\___/)
(>'.'<)
(")_(")

*/
