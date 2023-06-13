#include <stdio.h>
#include <stdlib.h>
#include "EmpAlu.h"
#include <string.h>

int crearArchTxtEmpFijo(const char* arch)
{
    int i=0;
    Empleado emp[]={{43458576,"Abadver","Camila",210000},{43565712,"Abadver","Pedro",100000},{39875614,"Ballero","Leticia",530000},{39872614,"Busto","Walle",120000},
                    {39875014,"Tristan","Catrina",350000},{39871414,"Xoles","Sol",430000}};
    Empleado* pEmp =emp;

    FILE *archE = fopen(arch,"wt");

    if(!archE)
        return 1;

    for(i=0;i<sizeof(emp)/sizeof(Empleado);i++)
    {
        fprintf(archE,"%08d%-20s%-20s%9.2f\n",pEmp->dni,pEmp->apellido,pEmp->nombre,pEmp->sueldo);
        pEmp++;
    }

    fclose(archE);
    return 0;
}

int crearArchTxtAluVar(const char* arch)
{
    int i=0;
    Alumno alu[]={{43458576,"Abadver","Camila",8},{13565712,"Azal","Luis",9},{39875614,"Ballero","Leticia",6},{12872614,"Wo","Leti",4},{39871414,"Xoles","Sol",10}};
    Alumno *pAlu=alu;

    FILE *archA= fopen(arch,"wt");

    if(!archA)
        return 1;

    for(i=0;i<sizeof(alu)/sizeof(Alumno);i++)
    {
        fprintf(archA,"%d|%s|%s|%d\n", pAlu->dni,pAlu->apellido,pAlu->nombre,pAlu->Promedio);
        pAlu++;
    }

    fclose(archA);
    return 0;
}

int convertirTxtaBin(const char* txt, const char* bin,void *obj, size_t tam, int txtBinTipo(char*,void*))
{
    FILE *archT = fopen(txt,"rt");
    FILE *archB = fopen(bin,"wb");

    if(!archT||!archB)
        return 1;

    char linea[200];

    while(fgets(linea,200,archT)) //no estoy contemplando errores de linea larga
    {
        if(txtBinTipo(linea, obj))
            fwrite(obj,tam,1,archB);
    }

    fclose(archT);
    fclose(archB);
    return 0;
}

int txtVarABin(char* linea, void* alumno) //cambiar a void*
{
    Alumno* alu = (Alumno*)alumno;

    char* pc= strchr(linea,'\n');
    *pc='\0';

    if(!pc)
        return 0;

    pc= strrchr(linea,'|');
    sscanf(pc+1,"%d", &(alu->Promedio));
    *pc='\0';

    pc= strrchr(linea,'|');
    strncpy(alu->nombre,pc+1,20);
    *pc='\0';

    pc= strrchr(linea,'|');
    strncpy(alu->apellido,pc+1,20);
    *pc='\0';

    pc= strrchr(linea,'|');
    sscanf(pc+1,"%d", &(alu->dni));

    return 1;
}

int mostrarArchBinario(char* nombreArch)
{
    FILE* archBin=fopen(nombreArch,"rb");
    if(!archBin)
        return 1;

    Alumno alu;
    printf("\n %s\n", nombreArch);

    fread(&alu,sizeof(Alumno),1,archBin);
    while(!feof(archBin))
    {
        printf("%-8d | %-20s |%-20s |%d \n",alu.dni,alu.apellido,alu.nombre,alu.Promedio);
        fread(&alu,sizeof(Alumno),1,archBin);

    }

    fclose(archBin);
    return 0;
}
