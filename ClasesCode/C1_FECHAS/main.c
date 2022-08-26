#include <stdio.h>
#include "Fechas.h"
int main()
{
    Fecha f =  ingresarFecha();

    puts("\nDIA RELATIVO:");
    printf("DiaRel:%d", calcDiaRelativo(f));

    puts("\nES UNA FECHA VALIDA?");
    esFechaValida(f);

    puts("\nFECHA SIGUIENTE");
    Fecha fSig = fechaSiguiente(f);
    printf("La fecha siguiente es: %d/%d/%d \n", fSig.dia, fSig.mes, fSig.anio );

    puts("\nSUMAR DIAS");
    int diasASumar=0;
    printf("Ingrese cantidad de dias a sumar a la fecha:");
    scanf("%d", &diasASumar);
    Fecha fNum = sumarDiasFecha(f,diasASumar);
    printf("La fecha resultante es: %d/%d/%d \n ", fNum.dia, fNum.mes, fNum.anio );

    puts("\nRESTAR DIAS");
    int diasARestar=0;
    printf("Ingrese cantidad de dias a restar a la fecha:");
    scanf("%d", &diasARestar);
    Fecha fRes = restarDiasFecha(f, diasARestar);
    printf("La fecha resultante es: %d/%d/%d \n ", fRes.dia, fRes.mes, fRes.anio );

    puts("\nCANTIDAD DE DIAS ENTRE FECHAS");
    Fecha f2 = ingresarFecha();
    printf("La cantidad de dias es %d", cantDiasEntreFechas(f,f2) );

    puts("\nDIA DE LA SEMANA");
    switch(calcDiaSemana(f))
    {
        case 1: puts("Lunes");
                break;
        case 2: puts("Martes");
                break;
        case 3: puts("Miercoles");
                break;
        case 4: puts("Jueves");
                break;
        case 5: puts("Viernes");
                break;
        case 6: puts("Sabado");
                break;
        case 7: puts("Domingo");
                break;
    }


    puts("\nDIA RELATIVO A FECHA:");
    int diaRelMano=0;
    scanf("%d", &diaRelMano);
    Fecha fdr = obtenerFecha(diaRelMano);
    printf("La fecha relativa es: %d/%d/%d \n", fdr.dia, fdr.mes, fdr.anio );

    return 0;
}
