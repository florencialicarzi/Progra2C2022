#include <stdio.h>
#include <stdlib.h>
#include "FechaPuntero.h"

int main()
{
    Fecha fechaMain;
    ingresarFechaValida(&fechaMain);

    //printf("Estructura: %d tam:%d \n Dia: %d tam:%d \n Mes: %d tam:%d \n Anio: %d tam:%d \n Letra:%c tam:%d", &fechaMain+1,sizeof(fechaMain),&(fechaMain.dia), sizeof(fechaMain.dia),&(fechaMain.mes), sizeof(fechaMain.mes),&(fechaMain.anio), sizeof(fechaMain.anio),&(fechaMain.letra),sizeof(fechaMain.letra));

    puts("\nDIA RELATIVO:");
    printf("DiaRel:%d", calcDiaRelativo(&fechaMain));

    puts("\nES UNA FECHA VALIDA?");
    esFechaValida(&fechaMain);

    puts("\nFECHA SIGUIENTE");
    Fecha fSig = fechaSiguiente(&fechaMain);
    printf("La fecha siguiente es: %d/%d/%d \n", fSig.dia, fSig.mes, fSig.anio );

    puts("\nSUMAR DIAS");
    int diasASumar=0;
    printf("Ingrese cantidad de dias a sumar a la fecha:");
    scanf("%d", &diasASumar);
    Fecha fNum = sumarDiasFecha(&fechaMain,diasASumar);
    printf("La fecha resultante es: %d/%d/%d \n ", fNum.dia, fNum.mes, fNum.anio );

    puts("\nRESTAR DIAS");
    int diasARestar=0;
    printf("Ingrese cantidad de dias a restar a la fecha:");
    scanf("%d", &diasARestar);
    Fecha fRes = restarDiasFecha(&fechaMain, diasARestar);
    printf("La fecha resultante es: %d/%d/%d \n ", fRes.dia, fRes.mes, fRes.anio );

    puts("\nCANTIDAD DE DIAS ENTRE FECHAS");
    Fecha f2;
    ingresarFechaValida(&f2);
    printf("La cantidad de dias es %d", cantDiasEntreFechas(&fechaMain,&f2) );

    puts("\nDIA DE LA SEMANA");
    switch(calcDiaSemana(&fechaMain))
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
