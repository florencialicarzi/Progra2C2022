#ifndef FECHAPUNTERO_H_INCLUDED
#define FECHAPUNTERO_H_INCLUDED

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

void ingresarFechaValida(Fecha* fecha);
int esFechaValida(const Fecha* f);
int calcDiaRelativo(const Fecha* f); //Base 1/1/1601 = 1
Fecha obtenerFecha (int diaRel);

int cantDiasMes(int mes, int anio);
int cantBisiestosHasta(int anio);

Fecha fechaSiguiente(const Fecha* f);
Fecha sumarDiasFecha(const Fecha* f, int dias);
Fecha restarDiasFecha(const Fecha* f, int dias);
int cantDiasEntreFechas(const Fecha* f1, const Fecha* f2);
int calcDiaSemana(const Fecha* f);


#endif // FECHAPUNTERO_H_INCLUDED
