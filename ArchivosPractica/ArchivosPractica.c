#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArchivosPractica.h"

int cargarArchivoTxtLV(const char* arch)
{
    int i;

    FILE* pf = fopen(arch, "wt");
    if(!pf)
        return 0;

    t_empleados empl[] =
    {
        {345345,"Acosta Santiago", 345.3564},
        {346745,"Alvarez Maximo",445.3564},
        {847565,"Baltazar Juancruz",245.3564},
        {978458,"Benitez Lucas",545.3564},
        {645643,"Caseres Alfonso",545.3564},
        {635635,"Eusebio Facundo",145.3564},
        {145565,"Fernandez Nacho",775.3564},
        {845785,"Perez Matias",335.3564},
        {875467,"Perez Matias",845.3564},
        {857465,"Perez Juan",874.3564},
        {234523,"Zeballos Ivan",645.3564},
    };

    t_alumno alum[] =
    {
        {345345,"Acosta Santiago", 3.2},
        {346745,"Alvarez Maximo",4.3},
        {847565,"Baltazar Juancruz",2.3},
        {978458,"Benitez Lucas",5.3},
        {645643,"Caseres Alfonso",7.2},
        {635635,"Eusebio Facundo",1.3},
        {145565,"Fernandez Nacho",7.9},
        {845785,"Perez Matias",3.3},
        {875467,"Perez Matias",8.4},
        {857465,"Perez Juan",8.7},
        {234523,"Zeballos Ivan",6.4},
    };

    for(i=0; i<sizeof(empl)/sizeof(t_empleados); i++)
    {
        fprintf(pf, "%d|%s|%.2f\n", empl[i].dni,empl[i].nya,empl[i].sueldo); //Archivo, Tipos de Datos, Que quiero escribir.
    }

    fclose(pf);

    return 1;
}

int cargarArchivoTxtLF(const char* arch)
{
    int i=0;
    t_empleados empl[] =
    {
        {345345,"Acosta Santiago", 345.3564},
        {346745,"Alvarez Maximo",445.3564},
        {847565,"Baltazar Juancruz",245.3564},
        {978458,"Benitez Lucas",545.3564},
        {645643,"Caseres Alfonso",545.3564},
        {635635,"Eusebio Facundo",145.3564},
        {145565,"Fernandez Nacho",775.3564},
        {845785,"Perez Matias",335.3564},
        {875467,"Perez Matias",845.3564},
        {857465,"Perez Juan",874.3564},
        {234523,"Zeballos Ivan",645.3564},
    };

    FILE* pf= fopen(arch,"wt");
    if(!pf)
        return 1;

    for(i=0;i<sizeof(empl)/sizeof(t_empleados);i++)
    {
        fprintf(pf,"%6d%-50s%3.2f\n",empl[i].dni,empl[i].nya,empl[i].sueldo);
    }

    fclose(pf);
    return 0;
}

int cargarArchivoBin(const char* arch)
{
    FILE* pf = fopen(arch, "wb");

    if(!pf)
        return 1;

    t_empleados empl[] =
    {
        {345345,"Acosta Santiago",345.3564},
        {346745,"Alvarez Maximo",445.3564},
        {847565,"Baltazar Juancruz",245.3564},
        {978458,"Benitez Lucas",545.3564},
        {645643,"Caseres Alfonso",545.3564},
        {635635,"Eusebio Facundo",145.3564},
        {145565,"Fernandez Nacho",775.3564},
        {845785,"Perez Matias",335.3564},
        {875467,"Perez Matias",845.3564},
        {857465,"Perez Juan",874.3564},
        {234523,"Zeballos Ivan",645.3564},
    };

    fwrite(&empl, sizeof(t_empleados), 11, pf);

    fclose(pf);

    return 0;
}

int convertirTxtABin(const char* archBin, const char* archTxt, void* trozar(char*,void*,char))
{
    char linea[100];
    t_empleados emp;

    FILE* pfTxt = fopen(archTxt,"rt");
    FILE* pfBin = fopen(archBin,"wb");

    if(!pfTxt||!pfBin)
        return 1;

    while(fgets(linea,100,pfTxt))
    {
        trozar(linea,&emp,'|');
        fwrite(&emp,sizeof(t_empleados),1,pfBin);
    }

    fclose(pfTxt);
    fclose(pfBin);
    return 0;
}

int BinATxt(const char* archBin, const char* archTxt, const char* formato)
{
    t_empleados empl;

    FILE* pfBin = fopen(archBin, "rb");
    FILE* pfTxt = fopen(archTxt, "wt");

    if(!pfBin || !pfTxt)
        return 1;

    fread(&empl, sizeof(t_empleados), 1, pfBin);

    while(!feof(pfBin))
    {
        fprintf(pfTxt, formato, empl.dni, empl.nya, empl.sueldo);
        fread(&empl, sizeof(t_empleados), 1, pfBin);
    }

    fclose(pfBin);
    fclose(pfTxt);

    return 0;
}
void trozarLongVariable(char* linea, t_empleados* emp, char corte)
{

    char* pl = strchr(linea,'\n');
    if(!pl)
        return;

    *pl='\0';
    pl= strrchr(linea,corte); //strRchr
    sscanf(pl+1,"%f", &(emp->sueldo));
    *pl='\0';

    pl= strrchr(linea,corte); //strRchr
    strcpy(emp->nya,pl+1);
    *pl='\0';

    sscanf(linea,"%d", &(emp->dni)); //el ultimo desde linea, no pl

}

void trozarLongFija(char* linea, t_empleados* emp)
{
    char* pl = strchr(linea,'\n');
    char* pt;
    if(!pl)
        return;
    *pl='\0';
    pl-=6;
    sscanf(pl,"%f", &(emp->sueldo));

    *pl='\0';
    pl-=50;
    pt=strstr(pl,"  ");
    *pt='\0';
    strcpy(emp->nya,pl);

    *pl='\0';
    sscanf(linea,"%d",&(emp->dni));

}

void mostrarEmpleados(const char* arch)
{
    t_empleados emp;
    FILE* pf = fopen(arch,"rb");
    if(!pf)
        return;

    fread(&emp,sizeof(t_empleados),1,pf);

    while(!feof(pf))
    {
        printf("%d, %s, %.2f\n",emp.dni,emp.nya,emp.sueldo);
        fread(&emp,sizeof(t_empleados),1,pf);
    }

    fclose(pf);
}
