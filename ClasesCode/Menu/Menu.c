#include <stdio.h>
#include <string.h>
#include "Menu.h"


char menuFuncion(const char* msj, const char* opc)
{
    char opta;
    int priVez=1;
    do
    {
        if(!priVez)
        {
            priVez=!priVez;
            puts("ERROR - Opcion NO valida.");
        }
        printf(msj);
        fflush(stdin);
        scanf("%c", &opta);
    }while(strchr(opc,opta) == NULL);

    return opta;
}

void probarMenu(void)
{
    char opcion;

    opcion = menuFuncion("ELIJA UNA OPCION\n\n"
                         "A- Alta\n"
                         "B- Baja\n"
                         "C- Consulta\n"
                         "M- Modificacion\n"
                         "S- Salir\n"
                         "--->",
                         "ABMCSL");
    printf("Opcion elegida: %c\n", opcion);
}
