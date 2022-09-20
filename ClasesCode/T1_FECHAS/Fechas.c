#include <stdio.h>
#include "Fechas.h"
#include <math.h>

Fecha ingresarFecha()
{
    Fecha f;
    puts("Ingrese una fecha(dd/mm/aaaa):");
    fflush(stdin); //Por el fin de linea
    scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);
    return f;
}
int esFechaValida(Fecha fecha)
{
    if(fecha.anio >= 1601)
        if(fecha.mes>= 1 && fecha.mes<= 12)
            if(fecha.dia>=1 && fecha.dia <= cantDiasMes(fecha.mes, fecha.anio))
               {
                 puts("Es fecha valida.");
                 return VERDADERO;
               }
    puts("La fecha no es valida");
    return FALSO;
}

int calcDiaRelativo(Fecha f) //Base 1/1/1601 = 1
{
    int acumDiasAnios = ((f.anio - ANIOBASE)*365);
    int cantBisiestos= cantBisiestosHasta(f.anio);
    int acumDiasMesAnt=0,i=0;
    for(i=1;i<f.mes;i++)
    {
        acumDiasMesAnt += cantDiasMes(i,f.anio);
    }
    //printf("diasAnios: %d | cantBisiestos: %d | acumMes: %d | diasMes: %d \n", acumDiasAnios, cantBisiestos,acumDiasMesAnt, f.dia);
    return (acumDiasAnios + cantBisiestos+ acumDiasMesAnt + f.dia );

}

Fecha obtenerFecha(int diaRel)
{
    Fecha fechaRel;
    Fecha finAnioAnterior= {31,12,1601};
    int acumMes=0, acumDias=0;
    int Anios = diaRel/365;
    int diasAnioActual=0;
    fechaRel.anio = ANIOBASE+Anios; //Calcule la cantidad de años

    finAnioAnterior.anio= fechaRel.anio -1;
    diasAnioActual= diaRel - (calcDiaRelativo(finAnioAnterior)); // Resto los dias de los años anteriores y obtengo los dias del año actual

    do
    {
        acumMes++;
        acumDias+= cantDiasMes(acumMes, fechaRel.anio);

    }while(acumDias < diasAnioActual);

    fechaRel.mes = acumMes;
    fechaRel.dia = cantDiasMes(acumMes, fechaRel.anio)- (acumDias- diasAnioActual);

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
    /*
    float cantAnios= anio - ANIOBASE; //ANIOBASE=1601
    float cuatroAnios = round(cantAnios/4);
    //printf("CantAnios: %f Anios/4: %f ", cantAnios, cuatroAnios);
    int siglos = cantAnios/100;
    int cuatroSiglos = cantAnios/400;
    return (cuatroAnios-siglos+cuatroSiglos);
    */
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


//Ejercicio 15: Desarrollar una función que a partir de una fecha obtenga la correspondiente al día siguiente.

Fecha fechaSiguiente(Fecha f)
{
    int cantMes = cantDiasMes(f.mes, f.anio);
    if(f.dia == cantMes)
    {   f.dia=1;
        if(f.mes == 12)
        {
            f.mes=1;
            f.anio+=1;
            return f;
        }
        f.mes+=1;
    }
    else
    {
        f.dia+=1;
    }
    return f;
}

//Ejercicio 16: Desarrollar una función que a partir de una fecha obtenga la que resulte de sumarle N días.
Fecha sumarDiasFecha(Fecha f, int dias)
{
    int auxDias = f.dia + dias;
    int cantMes = cantDiasMes(f.mes,f.anio);
    f.dia += dias;
    if(auxDias > cantMes)
    {
        auxDias-=cantMes;
        f.dia = auxDias;
        if(f.mes == 12)
        {
            f.mes=1;
            f.anio+=1;
            return f;
        }
        f.mes+=1;
    }
    return f;
}

//A partir de acá uso diaRel
//Ejercicio 17: Desarrollar una función que a partir de una fecha obtenga la que resulte de res-tarle N días.

Fecha restarDiasFecha(Fecha f, int dias)
{
    return obtenerFecha(calcDiaRelativo(f)-dias);
}

//Ejercicio 18: a partir de dos fechas obtenga la cantidad de díasque hay entre ellas.
int cantDiasEntreFechas(Fecha f1, Fecha f2)
{
    return calcDiaRelativo(f1)-calcDiaRelativo(f2);
}

//Ejercicio 19: fecha devuelva entero (0:lunes, 1:martes...)
int calcDiaSemana(Fecha f)
{
    int diaRel = calcDiaRelativo(f);
    int resto = diaRel % 7;
    if(resto==0)
        return 7;
    return resto;
}

