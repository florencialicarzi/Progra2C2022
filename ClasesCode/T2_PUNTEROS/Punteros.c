#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Punteros.h"
//el tamaño del puntero ocupa lo que sea el programa 32bits/64bits

//Para recibir la dir de memoria uso * (1 entero dir de memoria)
void ingresarFechaValida(Fecha* fecha)
{
    puts("Ingrese una fecha(D/M/A)");
    fflush(stdin);
    //Para acceder al struct desreferenciar cada campo. (&* o ->)
    scanf("%d/%d/%d", &(*fecha).dia, &fecha->mes, &fecha->anio);
    //Si fuera un int no hace falta desreferencia, le mando el puntero
    //pq ya es la dirección.
    while(!esFechaValida(fecha))//mando el puntero (FA00)
    {
        puts("Fecha invalida. ingrese otra fecha");
        scanf("%d/%d/%d", &(*fecha).dia, &fecha->mes, &fecha->anio);
    }
    //return fecha; NO HACE FALTA, YA LA OPERE
}

//Const pq no quiero modificar la fecha, solo operarla
int esFechaValida(const Fecha* f)
{
    if(f->anio >= 1601)
        if(f->mes >=1 && f->mes <=12)
            if(f->dia >=1 && f->dia <= cantDiasMes(f->mes, f->anio))
                return true;
    return false;
}

int cantDiasMes(int mes, int anio)
{
    static int cdm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((mes == 2) && (esBisiesto(anio)))
        return 29;

    return cdm[mes];
}
