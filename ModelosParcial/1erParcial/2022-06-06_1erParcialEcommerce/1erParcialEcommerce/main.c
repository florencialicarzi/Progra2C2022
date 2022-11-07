#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TDA_LISTA_IMPL_DINAMICA
#include "../Solucion1erParcialEcommerce/Solucion1erParcialEcommerce.h"
#include "../TDALista/TDALista.h"

#define ARG_CLIENTES    1
#define ARG_PRODUCTOS   2
#define ARG_REGLAS      3
#define ARG_OFERTAS     4

#define ERR_LINEA       5
#define TAM_LINEA       30

#define min(a,b) ((a) <= (b) ? (a) : (b))

int cargarReglasLista_ALU(const char* nombreArchReglas, Lista* pl);
int convertirTxtvarABin_ALU(char*, Regla*);
int cmpNivel_ALU(const void* d1, const void* d2);


int main(int argc, char* argv[])
{
    generarArchivoClientes(argv[ARG_CLIENTES]);
    generarArchivoProductos(argv[ARG_PRODUCTOS]);
    generarArchivoReglas(argv[ARG_REGLAS]);

    //generarArchivoOfertas(argv[ARG_CLIENTES], argv[ARG_PRODUCTOS], argv[ARG_REGLAS], argv[ARG_OFERTAS]);
    generarArchivoOfertas_ALU(argv[ARG_CLIENTES], argv[ARG_PRODUCTOS], argv[ARG_REGLAS], argv[ARG_OFERTAS]);

    if(mostrarArchivoOfertas(argv[ARG_OFERTAS]) != TODO_OK)
        printf("\n\nError al mostrar el archivo de ofertas.\n");

    char nombreArchivoOfertasTxt[251];
    cambiarExtension(argv[ARG_OFERTAS], nombreArchivoOfertasTxt, ".txt");

    //generarArchivoOfertasTxt(argv[ARG_OFERTAS], nombreArchivoOfertasTxt);
    generarArchivoOfertasTxt_ALU(argv[ARG_OFERTAS], nombreArchivoOfertasTxt);

    if(mostrarArchivoOfertasTxt(nombreArchivoOfertasTxt))
        printf("\n\nError al mostrar el archivo de ofertas txt.\n");

    return 0;
}


int generarArchivoOfertas_ALU(const char* nombreArchClientes, const char* nombreArchProductos, const char* nombreArchReglas, const char* nombreArchOfertas)
{
    FILE *archOfer = fopen(nombreArchOfertas, "wb");
    FILE *archCli = fopen(nombreArchClientes, "rb");
    FILE *archProd = fopen(nombreArchProductos, "rb");

    if(!archCli || !archOfer || !archProd )
    {
        fclose(archCli);
        fclose(archProd);
        fclose(archOfer);
        return ERR_ARCHIVO;
    }


    Cliente* clienteDat;
    Producto* prodDat;



    fclose(archCli);
    fclose(archProd);
    fclose(archOfer);
    return TODO_OK;
}


int generarArchivoOfertasTxt_ALU(const char* nombreArchivoOfertas, const char* nombreArchivoOfertasTxt)
{
    return TODO_OK;
}

int cargarReglasLista_ALU(const char* nombreArchReglas, Lista* lReglas)
{
    FILE* archRegl = fopen(nombreArchReglas, "rt");
    if(!archRegl)
        return ERR_ARCHIVO;

    Regla reglasDat;
    char linea[TAM_LINEA];
    int ret= TODO_OK;

    fgets(linea, TAM_LINEA, archRegl);
    while(!feof(archRegl))
    {
        ret = convertirTxtvarABin_ALU(linea, &reglasDat);
        if(ret==TODO_OK)
            insertarEnListaOrd(lReglas, &reglasDat, sizeof(Regla), cmpNivel_ALU);

        fgets(linea, TAM_LINEA, archRegl);
    }


    fclose(archRegl);
    return TODO_OK;
}

int convertirTxtvarABin_ALU(char* linea, Regla* reglasDat)
{
    char* car= linea;
    car= strchr(linea, '\n');
    if(!car)
        return ERR_LINEA;

    *car = '\0';
    car= strchr(linea, '\t');
    sscanf(car+1, "%f", &(reglasDat->minimoParaEnvioGratis));

    *car='\0';
    car= strchr(linea, '\t');
    sscanf(car+1, "%f", &(reglasDat->topeDescuento));

    *car='\0';
    car= strchr(linea, '\t');
    sscanf(car+1, "%f", &(reglasDat->porcDescuento));

    *car='\0';
    car= strchr(linea, '\t');
    sscanf(car+1, "%d", &(reglasDat->nivel));

    return TODO_OK;

}

int cmpNivel_ALU(const void* d1, const void* d2)
{
    Regla* r1 = (Regla*)d1;
    Regla* r2 = (Regla*)d2;

    return r1->nivel - r2->nivel;
}
