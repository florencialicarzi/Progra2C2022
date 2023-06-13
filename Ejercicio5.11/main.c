#include <stdio.h>
#include <stdlib.h>
#include "EmpAlu.h"
#define ArchEmp "ArchEmp.txt"
#define ArchAlu "ArchAlu.txt"
#define AluBin "ArchAluBin.dat"
int main()
{
    crearArchTxtEmpFijo(ArchEmp);
    crearArchTxtAluVar(ArchAlu);
    Alumno* alu;
    convertirTxtaBin(ArchAlu,AluBin,alu,sizeof(Alumno),txtVarABin);
    mostrarArchBinario(AluBin);
    printf("No se rompio todo al menos");
    return 0;
}
