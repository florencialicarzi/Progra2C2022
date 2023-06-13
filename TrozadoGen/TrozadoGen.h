#ifndef TROZADOGEN_H_INCLUDED
#define TROZADOGEN_H_INCLUDED

typedef struct
{
    int dni;
    int legajo;
    float promedio;
    int edad;
    char genero;

}tAlumno;

typedef struct
{
    char tipo[2];
    void* dir;
}TipoDir;

int grabarArchivoTxt(const char* archT);
int grabado_generico(const char* archT, const char* archB);
void trozado_generico(char* cabecera, char* linea, tAlumno* alu);
void identifTipo(char* cabecera, TipoDir* td,tAlumno* ta);
void mostrarAlu(const char* arch);

#endif // TROZADOGEN_H_INCLUDED
