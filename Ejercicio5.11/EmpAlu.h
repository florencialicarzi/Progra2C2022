#ifndef EMPALU_H_INCLUDED
#define EMPALU_H_INCLUDED

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float sueldo;
}Empleado;

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    int Promedio;
}Alumno;

int crearArchTxtEmpFijo(const char* arch);
int crearArchTxtAluVar(const char* arch);
int convertirTxtaBin(const char* txt, const char* bin, void *obj, size_t tam, int txtBinTipo(char*,void*));
int txtVarABin(char* linea, void* alumno);
int mostrarArchBinario(char* nombreArch);

#endif // EMPALU_H_INCLUDED
