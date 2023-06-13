#include <stdio.h>
#include <stdlib.h>
#include "Normalizar.h"

int main()
{
    char cad[] = "H*oLa,  CoMO  e 3ST$aS";

    printf("%s\n", cad);

    normalizarCad(cad);

    printf("%s", cad);

    return 0;
}
