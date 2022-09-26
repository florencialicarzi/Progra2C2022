#include <stdio.h>
#include <stdlib.h>
#include "TextoABinario.h"

int main()
{
    printf("CONVERTIR ARCHIVOS ...\n");
    convertirTxtaBin("archTxtEmp.txt","archBinEmp.dat", txtVarABin);
    printf("ARCHIVO BINARIO GENERADO\n");
    mostrarArchBinario("archBinEmp.dat");

    //convertirTxtaBin("archTxtEmpII.txt","archBinEmpII.dat", txtVarAFijo);
    //mostrarArchBinario("archBinEmpII.dat");
    return 0;
}
