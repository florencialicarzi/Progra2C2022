#include <stdio.h>
#include <stdlib.h>
#include "FuncionAPuntero.h"
int main()
{
    int ceProd;
    Producto vProd[100];
    cargaProds(vProd,&ceProd);
    ordenarSelGenerico(vProd,ceProd,sizeof(Producto),cmpProd);
    mostrarVec(vProd,ceProd,sizeof(Producto),mostrarProd);

    return 0;
}

void cargaProds(Producto* vProd, int* ceProd )
{
    int flag=0;
    void* ult= vec+(ce-1)*sizeof(Producto)
    for(int* i= vProd, i<ult, i+=sizeof(Producto))
    while(flag!=0)
    {
        printf("INGRESAR PRODUCTO N° %d (Para terminar ingrese 0)\n", *ceProd +1);
        printf("Ingresar Codigo:")
        scanf("%d", vProd->cod);
        printf("Ingresar Stock:")
        scanf("%d", vProd->stock);
        if()
    }
}


int cmpProdCod(const void* p1, const void* p2)
{
    const Producto* prod1= (Producto*)p1; //casteo puntero a Producto(struct)
    const Producto* prod2= (Producto*)p2;
    return strcmp(prod1->cod, prod2->cod); //strcmp de string.h es con chat*
}

int cmpProdStockCod(const void* p1, const void* p2)// dos campos de comparacion
{
    const Producto* prod1= (Producto*)p1;
    const Producto* prod2= (Producto*)p2;

    int comp= prod1->stock - prod2->stock;
    if(comp!=0)
        return comp;
    return strcmp(prod1->cod, prod2->cod);
}

