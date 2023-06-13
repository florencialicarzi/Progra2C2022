#include <stdio.h>
#include <stdlib.h>
#include "ArchivosPractica.h"
#define archT "empleados.txt"
#define archB "empleados.bin"
#define ArchT2 "empleados2.txt"
#define archB2 "empleados2.bin"
#define arch5 "empleados3.bin"
#define arch6 "empleados4.txt"

int main()
{
    cargarArchivoTxtLV(archT);
    convertirTxtABin(archB,archT,(void*)trozarLongVariable);
    mostrarEmpleados(archB);

    cargarArchivoTxtLF(ArchT2);
    convertirTxtABin(archB2,ArchT2,(void*)trozarLongFija);
    mostrarEmpleados(archB2);


    cargarArchivoBin(arch5);
    BinATxt(arch5, arch6, "%d|%s|%.2f\n");
    mostrarEmpleados(arch5);



    return 0;
}
