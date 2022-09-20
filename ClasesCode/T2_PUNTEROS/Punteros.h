#ifndef PUNTEROS_H_INCLUDED
#define PUNTEROS_H_INCLUDED
#define esBisiesto(a) (((a) %4 == 0 && (a) %100 != 0) || (a) % 400 == 0)

typedef struct
{
    int dia;
    int mes;
    int anio;

}Fecha;

void ingresarFechaValida(Fecha* fecha);
int esFechaValida(const Fecha* f);
int cantDiasMes(int mes, int anio);

#endif // PUNTEROS_H_INCLUDED
