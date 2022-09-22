#include <stdio.h>
#include "ArchivosDeTexto.h"

int imprimirArchivo(FILE* archivo, char tipoFormato)
{
    FILE* archProds = fopen("Productos.dat", "rb");
    if(!archProds)
    {
        printf("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }

    char* formato = tipoFormato == 'v'? "%s\t%s\t%.2f\t%d\n" : "%-10s%-10s%09.2f%05d" ;
    Producto prod;
    fread(&prod,sizeof(Producto),1,archProds);
    while(!feof(archProds))
    {
        fprintf(archivo,formato,prod.cod,prod.des,prod.pre,prod.stock);
        fread(&prod, sizeof(Producto),1,archProds);
    }
    fclose(archProds);
    return TODO_OK;
}

int convertirTxtABin(const char* nombreTxt, char tipoFormato, const char* nombreBin)
{
    FILE* archTxt = fopen(nombreTxt, "rt");
    FILE* archBin = fopen(nombreBin, "wb");

    if(!archTxt || !archBin)
    {
        printf("No se pudo abrir el archuivo");
        return ERR_ARCHIVO;
    }

    //v = longitud variable
    char* formato = tipoFormato == 'v'? "%s\t%s\t%.2f\t%d\n" : "%10s%10s%9f%5d" ;

    Producto prod;
    fscanf(archTxt, formato, prod.cod, prod.des, &prod.pre, &prod.stock);
    while(!feof(archTxt))
    {
        //escribe en el binario
        fwrite(&prod, sizeof(Producto),1,archBin);
        //lee linea archivo de texto
        fscanf(archTxt, formato, prod.cod, prod.des, &prod.pre, &prod.stock);
    }
    fclose(archTxt);
    fclose(archBin);

    return TODO_OK;
}

int actualizarArchivo(char* nombre)
{
    FILE* archProds= fopen(nombre, "r+b");
    if(!archProds)
    {
        printf("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }

    Producto prod;
    fread(&prod, sizeof(Producto),1,archProds);
    while(!feof(archProds))
    {
        prod.pre *= 1.20;
        fseek(archProds, (long)-sizeof(Producto), SEEK_CUR);
        fwrite(&prod, sizeof(Producto),1,archProds);
        fseek(archProds,0L, SEEK_CUR);
        fread(&prod, sizeof(Producto),1,archProds);
    }
    fclose(archProds);
}
