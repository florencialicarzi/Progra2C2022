#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "FechaPuntero.h"

void ingresarFechaValida(Fecha* fecha)
{
    puts("Ingrese una fecha(D/M/A)");
    fflush(stdin);
    scanf("%d/%d/%d", &(*fecha).dia, &fecha->mes, &fecha->anio);
    while(!esFechaValida(fecha))
    {
        puts("Fecha invalida. ingrese otra fecha");
        scanf("%d/%d/%d", &(*fecha).dia, &fecha->mes, &fecha->anio);
    }
}

int esFechaValida(const Fecha* f)
{
    if(f->anio >= 1601)
        if(f->mes >=1 && f->mes <=12)
            if(f->dia >=1 && f->dia <= cantDiasMes(f->mes, f->anio))
            {
                puts("Es una fecha valida");
                return true;
            }
    puts("La fecha no es valida");
    return false;
}

int calcDiaRelativo(const Fecha* f) //Base 1/1/1601 = 1
{
    int acumDiasAnios = ((f->anio - ANIOBASE)*365);
    int cantBisiestos= cantBisiestosHasta(f->anio);
    int acumDiasMesAnt=0,i=0;
    for(i=1;i<f->mes;i++)
    {
        acumDiasMesAnt += cantDiasMes(i,f->anio);
    }
    //printf("diasAnios: %d | cantBisiestos: %d | acumMes: %d | diasMes: %d \n", acumDiasAnios, cantBisiestos,acumDiasMesAnt, f.dia);
    return (acumDiasAnios + cantBisiestos+ acumDiasMesAnt + f->dia );

}

Fecha obtenerFecha(int diaRel)
{
    Fecha fechaRel={31,12,1601};
    int anio=0, secAnios=ANIOBASE, mes=1;
    while(diaRel>=(esBisiesto(secAnios) ? 366 : 365))
    {
       if(esBisiesto(secAnios))
       {
           diaRel-=366;
       }
       else{
            diaRel -=365;
       }
        anio++;
        secAnios++;
    }

    if(diaRel==0)
    {
        fechaRel.anio= ANIOBASE+anio-1;
        return fechaRel;
    }

    fechaRel.anio=ANIOBASE + anio;

    while(diaRel>cantDiasMes(mes,fechaRel.anio))
    {
        diaRel -= cantDiasMes(mes,fechaRel.anio);
        mes++;
    }
    fechaRel.mes= mes;
    fechaRel.dia= diaRel;
    return fechaRel;
}


int cantDiasMes(int mes, int anio)
{
    static int cdm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((mes == 2) && (esBisiesto(anio)))
        return 29;

    return cdm[mes];
}

int cantBisiestosHasta(int anio)
{
    int i=0,cantBis=0;
    for(i=1601;i<anio;i++)
    {
        if(esBisiesto(i))
        {
             cantBis++;
        }
    }
    return cantBis;
}

Fecha fechaSiguiente(const Fecha* f)
{
    Fecha fsig = {f->dia,f->mes,f->anio};
    int cantMes = cantDiasMes(f->mes, f->anio);
    if(f->dia == cantMes)
    {   fsig.dia=1;
        if(f->mes == 12)
        {
            fsig.mes=1;
            fsig.anio+=1;
            return fsig;
        }
        fsig.mes+=1;
    }
    else
    {
        fsig.dia+=1;
    }
    return fsig;
}

Fecha sumarDiasFecha(const Fecha* f, int dias)
{
    Fecha fRes = obtenerFecha(calcDiaRelativo(f)+dias);
    return fRes;
}

Fecha restarDiasFecha(const Fecha* f, int dias)
{
    Fecha fRes = obtenerFecha(calcDiaRelativo(f)-dias);
    return fRes;
}

int cantDiasEntreFechas(const Fecha* f1, const Fecha* f2)
{
    return calcDiaRelativo(f1)-calcDiaRelativo(f2);
}

int calcDiaSemana(const Fecha* f)
{
    int diaRel = calcDiaRelativo(f);
    int resto = diaRel % 7;
    if(resto==0)
        return 7;
    return resto;
}

