#ifndef TEXTOABINARIO_H_INCLUDED
#define TEXTOABINARIO_H_INCLUDED

#define TODO_OK 0
#define ARCH_ERROR 2
#define ERR_LINEA_LARGA 3
#define ERROR_FATAL 4

#define TAM_LINEA 200
#define TAM_APYNOM 101
#define TAM_SUELDO 10
#define TAM_FECHA 8

typedef struct
{
    int d;
    int m;
    int a;
}tFecha;

typedef struct
{
    int doc;
    char apynom[TAM_APYNOM];
    tFecha fnac;
    float sueldo;
}Empleado;

typedef int(*Paf)( char*, Empleado*);

int convertirTxtaBin(const char* nombreTxt, const char* nombreBin, Paf cTxtABinTipo);
int txtVarABin(char* linea, Empleado* emp);
int txtFijoABin(char* linea, Empleado* emp);
_Bool errorFatal(int codRet);
int mostrarArchBinario();

#endif // TEXTOABINARIO_H_INCLUDED
