#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Ej5.13.h"

void mostrarArchBin_esp(const char* arch)
{
    int num=0;

    FILE* pf = fopen(arch,"rb");
    if(!pf)
        return;

    fread(&num,sizeof(int), 1,pf);

    while(!feof(pf))
    {
        printf("%d ", num);
        fread(&num,sizeof(int), 1,pf);
    }

    fclose(pf);
}

void mostrarArchTxt_esp(const char* arch)
{
    char num[4];

    FILE* pf = fopen(arch,"rt");
    if(!pf)
        return;

    while(fgets(num,4,pf))
    {
        printf("%s ", num);
    }

    fclose(pf);
}

void generarBinRand(const char* arch)
{
    int i=0,num=0;
    FILE* pfB = fopen(arch,"wb");

    srand(time(NULL));

    for(i=0; i<90; i++)
    {
        num = (rand()%899)+100;
        fwrite(&num,sizeof(int),1, pfB);
    }

    fclose(pfB);
}

void triArchBin(const char* arch1,const char* arch2,const char* arch3,const char* archA)
{
    int vecNum[30]={0};

    FILE* pA = fopen(archA,"rb");
    FILE* p1= fopen(arch1,"wb");
    FILE* p2= fopen(arch2,"wb");
    FILE* p3= fopen(arch3,"wb");

    if(!pA || !p1 || !p2 || !p3)
        return;

    fread(vecNum,sizeof(int),30,pA);
    fwrite(vecNum, sizeof(int),30,p1);

    fread(vecNum,sizeof(int),30,pA);
    fwrite(vecNum, sizeof(int),30,p2);

    fread(vecNum,sizeof(int),30,pA);
    fwrite(vecNum, sizeof(int),30,p3);

    fclose(pA);
    fclose(p1);
    fclose(p2);
    fclose(p3);
}

void generarBinATxt(const char* archB, const char* archT)
{
    int i=0,num=0;
    FILE* pB= fopen(archB,"rb");
    FILE* pT= fopen(archT,"wt");

    for(i=0;i<30;i++)
    {
        fread(&num,sizeof(int),1,pB);
        fprintf(pT,"%d",num);
    }

    fclose(pB);
    fclose(pT);
}

void ofuscarNum(const char* arch1, const char* archt1, int cant)
{
    int i=0;
    char num;

    FILE* pf = fopen(arch1,"rb");
    FILE* pfT = fopen(archt1,"wb");

    for(i=0;i<90;i++)
    {
        num= fgetc(pf);
        num+=cant;
        if(num>90)
            num-=26;
        fprintf(pfT,"%c",num);
    }

    fclose(pf);
    fclose(pfT);
}

int ordenarArchText(const char* arch1, const char* arch2, int ce, size_t tam)
{
    char vec[ce]; //creo vector para el qsort

    FILE* archTxt1 = fopen(arch1, "rt"); //abro arch lectura escritura (pf al inicio)
    FILE* archTxt2 = fopen(arch2, "wt");

    if(!archTxt1)
        return 1;

    if(!archTxt2)
        return 1;

    fgets(vec, ce, archTxt1);

    qsort(vec, (ce-1)/tam, tam, comparar_cadenas); //ordeno

    fprintf(archTxt2, "%s", vec);

    fclose(archTxt1); //cierro archivo
    fclose(archTxt2); //cierro archivo
    return 0;
}

int comparar_cadenas(const void* cad1, const void *cad2)
{

    return strcmp((char*)cad1, (char*)cad2);
}

int juntarTxts(const char* arch1, const char* arch2, const char* arch3, const char* arch4)
{
    char linea[91];
    char linea2[271];

    FILE* archord = fopen(arch1, "w+t");
    FILE* archord1 = fopen(arch2, "rt");
    FILE* archord2 = fopen(arch3, "rt");
    FILE* archord3 = fopen(arch4, "rt");

    if(!archord)
        return 1;

    if(!archord1)
        return 1;

    if(!archord2)
        return 1;

    if(!archord3)
        return 1;


    fgets(linea, 91, archord1);
    fprintf(archord, "%s", linea);

    fgets(linea, 91, archord2);
    fprintf(archord, "%s", linea);

    fgets(linea, 91, archord3);
    fprintf(archord, "%s", linea);

    fseek(archord, 0, SEEK_SET);

    fgets(linea2, 271, archord);

    qsort(linea2, 90, 3, comparar_cadenas);

    fseek(archord, 0, SEEK_SET);

    fprintf(archord, "%s", linea2);

    fclose(archord);
    fclose(archord1);
    fclose(archord2);
    fclose(archord3);

    return 0;
}
