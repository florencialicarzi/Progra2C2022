#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../Librerias/Menu/Menu.h"
#include "Vectores.h"

int main()
{
    int tam,cantElem,posAMod,elemAMod;
    elegirCantPosiciones(&tam);
    int vecMain[tam];

    char opcion;
    do
    {
        opcion = menuFuncion(MENU_MSJ,MENU_OPC);
        system("cls");
        opcion = toupper(opcion);
        switch(opcion)
        {
            case 'A': cargarVector(vecMain, &tam, &cantElem); break;
            case 'B': insertarEnPos(vecMain, &tam, &cantElem, &posAMod, &elemAMod); break;
            case 'C': insertarEnOrden(vecMain, &tam, &cantElem,&elemAMod); break;
            case 'D': eliminarEnPos(vecMain, &tam, &cantElem,&posAMod); break;
            case 'E': eliminarPrimerAparicionX(vecMain, &tam, &cantElem,&elemAMod); break;
            case 'F': eliminarTodosLosX(); break;

        }
        system("cls");
        mostrarVector(vecMain,&tam,&cantElem);
    }while(opcion!= 'S');

    return 0;
}
