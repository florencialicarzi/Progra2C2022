#include <stdio.h>
#include "TextoABinario.h"

int convertirTxtaBin(const char* nombreTxt, const char* nombreBin/*, void* convertTipoArch*/)
{
    FILE* archTxt = fopen(nombreTxt, "rt");
    FILE* archBin = fopen(nombreBin, "wb");

    if(!archTxt || !archBin)
        return ARCH_ERROR;

    int codRet= TODO_OK;
    bool errF=false;
    char linea[TAM_LINEA];
    Empleado emp;

    while(!errF && fgets(linea,TAM_LINEA,archTxt)) //fgets retorna |cadena |vacio: null=0 |
    {
        codRet=txtABin(linea, &emp);
        errF = errorFatal(codRet);
        if(codRet==TODO_OK)
            fwrite(&emp, sizeof(Empleado),1,1 archBin);
        //opt: poner un else con los distintos flags de error;
    }
    fclose(archTxt);
    fclose(archBin);

    return errF? TODO_OK: ERROR_FATAL;
}

int txtVarABin(char* linea, Empleado* emp)
{
    char* act = strchr(linea,'\n');
    if(!act)
        return ERR_LINEA_LARGA;

    *act='\0';
    act = strrchr(linea,'|');
    //mueve el fseek hasta la ultima '|'
    sscanf(act+1, "%f",&emp->sueldo);
    //inserto el \0 para que no encuentre el | en la proxima busqueda
    *act='\0';
    act = strrchr(linea,'|');
    sscanf(act+1, "%d/%d/%d",&emp->fnac.d,&emp->fnac.m,&emp->fnac.a); //struct dentro de puntero a struct
    *act='\0';
    act = strrchr(linea,'|');
    strcpy(emp->apynom,act+1,TAM_APYNOM -1);
    *(emp->apynom + TAM_APYNOM -1)= '\0'; //direccion del char para insertar el \0 en el apynom | dos desref -> y *
    *act='\0';
    sscanf(linea, "%d", &emp->doc); //linea pq es el ultimo, va hasta el principio

    //A esto podemos agregar validaciones a cada campo antes de sscanf y grabar
    return TODO_OK;
}

int txtFijoABin(char* linea, Empleado* emp)
{
    char* act = strchr(linea,'\n');
    if(!act)
        return ERR_LINEA_LARGA;

    *act='\0';
    act -= TAM_SUELDO; //10
    sscanf(act, "%f", &emp->sueldo);
    *act='\0';
    act -= TAM_FECHA; //8
    sscanf(act, "%2d/%2d/%4d",&emp->fnac.d,&emp->fnac.m,&emp->fnac.a); //decir cuanto ocupa cada campo
    *act='\0';
    act -= TAM_APYNOM-1; //-1 del '\0'
    //conviene grabar sin los espacios sobrantes el nombre, sol.
    strncpy(emp->apynom,act,TAM_APYNOM -1);
    *(emp->apynom + TAM_APYNOM -1)= '\0';
    *act='\0';
    sscanf(linea, "%d", &emp->doc);

    return TODO_OK;
}
