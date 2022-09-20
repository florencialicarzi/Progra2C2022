#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define ANIOBASE 1601

#define esBisiesto(a) (((a) %4 == 0 && (a) %100 != 0) || (a) % 400 == 0)

typedef struct
{
    int dia;
    int mes;
    int anio;

}Fecha;

Fecha ingresarFecha();
int esFechaValida(Fecha f);
int calcDiaRelativo(Fecha f);
Fecha obtenerFecha(int diaRel);

int cantDiasMes(int mes, int anio);
int cantBisiestosHasta(int anio);

Fecha fechaSiguiente(Fecha f);
Fecha sumarDiasFecha(Fecha f, int dias);
Fecha restarDiasFecha(Fecha f, int dias);
int cantDiasEntreFechas(Fecha f1, Fecha f2);
int calcDiaSemana(Fecha f);

#endif // FECHAS_H_INCLUDED
