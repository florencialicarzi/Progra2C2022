#include <stdio.h>
#include <stdlib.h>

#include "utiles.h"
#include "vectorEnteros.h"

#define TAM 10

int main()
{

/*

    int a, b;

    printf("Ingresa numero 1: ");
    scanf("%d", &a);

    printf("Ingresa numero 2: ");
    scanf("%d", &b);

    printf("a: %d\nb: %d", a, b);

    intercambioEnteros(&a, &b);

    printf("\na: %d\nb: %d", a, b);

*/

    int vec1[TAM] = {7,6,8,5,9,2,1,3};
    int vec2[TAM] = {7,6,3,5};

    //compararVectores(vec1, vec2, 4);

    mostrarVector(vec1, 8);
    insertarVecPos(vec1, 22, 2, 8);
    puts("");
    mostrarVector(vec1, 9);



    return 0;
}

/*
(\___/)
(>'.'<)
(")_(")

*/
