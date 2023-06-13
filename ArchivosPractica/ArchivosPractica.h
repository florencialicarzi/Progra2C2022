#ifndef ARCHIVOSPRACTICA_H_INCLUDED
#define ARCHIVOSPRACTICA_H_INCLUDED

typedef struct
{
    int dni;
    char nya[50];
    float sueldo;

}t_empleados;

typedef struct
{
    int dni;
    char nya[50];
    float prom;

}t_alumno;

int cargarArchivoTxtLV(const char* arch);
int cargarArchivoTxtLF(const char* arch);
int cargarArchivoBin(const char* arch);
int convertirTxtABin(const char* archBin, const char* archTxt, void* trozar(char*,void*,char));
int BinATxt(const char* archBin, const char* archTxt, const char* formato);
void trozarLongVariable(char* linea, t_empleados* emp, char corte);
void trozarLongFija(char* linea, t_empleados* emp);
void mostrarEmpleados(const char* arch);

#endif // ARCHIVOSPRACTICA_H_INCLUDED
