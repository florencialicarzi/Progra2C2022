#include <stdio.h>
#include <stdlib.h>
#include "Cadenas.h"

int main()
{
    system("chcp 65001>nul"); //Para ver tildes
    char cad[]={"hola"};
    char cadOrd[10];
    cadOrd = ordenarCadena(cad,4);
    //mostrarCadena(cadOrd);
    //printf("%s", cadOrd);
    return 0;
}
