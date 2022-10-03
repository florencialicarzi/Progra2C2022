#include <stdio.h>
#include <stdlib.h>
//define PILA_EST o PILA_DIN
#include "TDA_Pila.h"

//Sumar 9947389 57267

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        puts("Cantidad de parametros incorrecta");
        return 1;
    }

    char* suma = sumar(argv[1],argv[2]);
    printf("%s", suma);
    free(suma);
    return 0;
}
