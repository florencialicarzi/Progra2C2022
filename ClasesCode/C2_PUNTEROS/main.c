#include <stdio.h>
#include <stdlib.h>
#include "Punteros.h"

int main()
{
    Fecha fechaMain;

    //Uso el & parqa enviarle la dir. de memoria a la función
    ingresarFechaValida(&fechaMain);
    printf("La fecha %d/%d/%d es valida\n", fechaMain.dia, fechaMain.mes, fechaMain.anio);
    return 0;
}
