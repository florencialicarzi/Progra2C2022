#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TrozadoGen.h"

int grabarArchivoTxt(const char* archT)
{
    int i;
    tAlumno alu[]={
                      {10,1001,9.5,23,'M'},
                      {20,1003,5.5,21,'F'},
                      {30,1090,8.0,25,'X'},
                      {10,1001,9.5,23,'M'},
                      {20,1003,5.5,21,'F'}

                  };

    FILE* pfT= fopen(archT,"wt");

    if(!pfT)
        return 1;

    //fprintf(pfT,"%s|%s|%s|%s|%s\n","dni","promedio","edad","legajo","genero");
    fprintf(pfT,"%s|%s|%s|%s|%s\n","legajo","dni","promedio","edad","genero");
    for(i=0;i<(sizeof(alu)/sizeof(tAlumno));i++)
    {
        //fprintf(pfT,"%d|%.2f|%d|%d|%c\n",alu[i].dni,alu[i].promedio,alu[i].edad,alu[i].legajo,alu[i].genero);
        fprintf(pfT,"%d|%d|%.2f|%d|%c\n",alu[i].legajo,alu[i].dni,alu[i].promedio,alu[i].edad,alu[i].genero);
    }

    fclose(pfT);

    return 0;
}


int grabado_generico(const char* archT, const char* archB)
{
    tAlumno alu;
    char cabecera[33];
    char linea[33];


    FILE* pfT= fopen(archT,"rt");
    FILE* pfB= fopen(archB,"wb");

    if(!pfT||!pfB)
        return 1;

    fgets(cabecera,33,pfT);


    while(fgets(linea,33,pfT))
    {
        trozado_generico(cabecera,linea,&alu);
        fwrite(&alu,sizeof(tAlumno),1,pfB);
    }

    fclose(pfT);
    fclose(pfB);

    return 0;

}

 void trozado_generico(char* cab, char* linea, tAlumno* alu)
 {
    char cabecera[33];
    int i;
    TipoDir td;

    strcpy(cabecera,cab);

    char* pc = strchr(cabecera,'\n');
    char* pl = strchr(linea,'\n');

    if(!pc||!pl)
        return;

    for(i=0;i<4;i++)
    {
        *pc='\0';
        *pl='\0';

        pc=strrchr(cabecera,'|');
        pl=strrchr(linea,'|');

        identifTipo(pc+1,&td,alu);
        sscanf(pl+1,td.tipo,td.dir);
    }

    *pc='\0';
    *pl='\0';

    identifTipo(cabecera,&td,alu);
    sscanf(linea,td.tipo,td.dir);

 }

void identifTipo(char* cabecera, TipoDir* td,tAlumno* ta)
{
    char c[2] = "%c";
    char d[2] = "%d";
    char f[2] = "%f";

    if(strcmp(cabecera,"genero")== 0)
    {
        strcpy(td->tipo,c);
        td->dir = &(ta->genero);
        return;
    }

    if(strcmp(cabecera,"legajo")== 0)
    {
        strcpy(td->tipo,d);
        td->dir = &(ta->legajo);
        return;
    }

    if(strcmp(cabecera,"edad")== 0)
    {
        strcpy(td->tipo,d);
        td->dir = &(ta->edad);
        return;
    }

    if(strcmp(cabecera,"promedio")== 0)
    {
        strcpy(td->tipo,f);
        td->dir = &(ta->promedio);
        return;
    }

    if(strcmp(cabecera,"dni")== 0)
    {
        strcpy(td->tipo,d);
        td->dir = &(ta->dni);
        return;
    }
}

void mostrarAlu(const char* arch)
{
    tAlumno alu;

    FILE* pf = fopen(arch, "rb");

    if(!pf)
        return;

    fread(&alu, sizeof(tAlumno), 1, pf);

    while(!feof(pf))
    {
        printf("%d|%d|%.2f|%d|%c\n", alu.legajo, alu.dni, alu.promedio, alu.edad, alu.genero);
        fread(&alu, sizeof(tAlumno), 1, pf);
    }

    fclose(pf);

}



