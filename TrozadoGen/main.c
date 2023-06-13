#include <stdio.h>
#include <stdlib.h>
#include "TrozadoGen.h"
#define archT "ArchAlu.txt"
#define archB "ArchAluB.dat"
int main()
{
    grabarArchivoTxt(archT);
    grabado_generico(archT, archB);
    mostrarAlu(archB);
    return 0;
}
