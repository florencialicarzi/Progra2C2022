#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../Librerias/Menu/Menu.h"
#include "Vectores.h"

int main()
{
    int cant;
    elegirCantPosiciones(&cant);
    int vecMain[cant];

    char opcion;
    do
    {
        opcion = menuFuncion(MENU_MSJ,MENU_OPC);
        system("cls");
        opcion = toupper(opcion);
        switch(opcion)
        {
            case 'A': cargarVector(vecMain, &cant); break;
            case 'B': insertarEnPos(); break;
            case 'C': insertarEnOrden(); break;
            case 'D': eliminarEnPos(); break;
            case 'E': eliminarPrimerAparicionX(); break;
            case 'F': eliminarTodosLosX(); break;

        }
        system("cls");
        mostrarVector(vecMain,&cant);
    }while(opcion!= 'S');

    return 0;
}
