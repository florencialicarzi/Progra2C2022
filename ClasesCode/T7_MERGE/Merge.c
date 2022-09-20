#include <stdio.h>
#include <string.h>
#include "Merge.h"

int inicializarProdMov(void* prod, void* movs,int cantProd, int cantMov)
{
    FILE* archP= fopen("Productos.dat","wb");
    FILE* archM= fopen("Movimientos.dat", "wb");

    if(!archP || !archM)
    {
        printf("holi?");
        return 1;
    }

    fwrite(prod, sizeof(Producto),cantProd,archP);
    fwrite(movs, sizeof(Movimiento),cantMov,archM);

    fclose(archP);
    fclose(archM);

    return 0;
}

int actualizarProds(const char* productosA, const char* movimientosA) //nombresArch
{
    FILE* archProds = fopen(productosA, "rb");
    FILE* archMovs = fopen(movimientosA, "rb");
    FILE* archProdsTmp = fopen("Temporal.tmp", "wb");

    if(!archProds || !archMovs || !archProdsTmp)
        return 0;

    Producto prod;
    Movimiento mov;
    int comp;

    fread(&prod,sizeof(Producto),1,archProds);
    fread(&mov, sizeof(Movimiento),1,archMovs);
    while(!feof(archProds) && !feof(archMovs))
    {
        comp= strcmp(prod.cod, mov.cod);
        if(comp<0) //Producto sin modificaciones
        {
            fwrite(&prod, sizeof(Producto),1,archProdsTmp);
            fread(&prod,sizeof(Producto),1,archProds);
        }
        if(comp==0) //actualizo stock
        {
            prod.stock+= mov.cant;
            //no grabo todavia pq puede haber otro del mismo
            fread(&mov,sizeof(Movimiento),1,archMovs);
        }
        if(comp>0) //prod nuevo
        {
            actProdNue(&mov,archMovs,archProdsTmp);
        }

    }
    while(!feof(archProds))
    {
        fwrite(&prod, sizeof(Producto),1,archProdsTmp);
        fread(&prod,sizeof(Producto),1,archProds); //Hasta llegar a feof
    }
    while(!feof(archMovs))//todos productos nuevos
    {
        actProdNue(&mov,archMovs,archProdsTmp);
    }

    fclose(archProds);
    fclose(archMovs);
    fclose(archProdsTmp);

    mostrarMerge();

    remove(productosA);
    rename("Temporal.tmp",productosA);

    return 1;
}

void actProdNue(Movimiento* mov, FILE* archMovs, FILE* archProdsTmp)
{
    Producto prodNue={"","",0,0};

    strcpy(prodNue.cod, mov->cod);
    prodNue.stock = mov->cant;
    fread(mov,sizeof(Movimiento),1,archMovs);
    while(!feof(archMovs)&& strcmp(prodNue.cod,mov->cod)==0)
    {
        prodNue.stock+=mov->cant;
        fread(mov,sizeof(Movimiento),1,archMovs);
    }
    fwrite(&prodNue, sizeof(Producto),1,archProdsTmp);
}

int extraerYMostrarProdsYMovs()
{
    FILE* archProds=fopen("Productos.dat","rb");
    FILE* archMovs=fopen("Movimientos.dat","rb");
    if(!archProds || !archMovs)
        return 1;

    Producto prod;
    Movimiento mov;

    fread(&prod,sizeof(Producto),1,archProds);
    fread(&mov, sizeof(Movimiento),1,archMovs);
    printf("PRODUCTOS.DAT\n");
    while(!feof(archProds))
    {
        printf("cod: %-4s nombre: %-21s precio: %-5d stock: %d\n",prod.cod,prod.desc,prod.precio,prod.stock);
        fread(&prod,sizeof(Producto),1,archProds);
    }

    printf("\nMOVIMIENTOS.DAT \n");
    while(!feof(archMovs))
    {
        printf("cod: %-4s stock: %d \n",mov.cod,mov.cant);
        fread(&mov, sizeof(Movimiento),1,archMovs);
    }
    fclose(archProds);
    fclose(archMovs);
    return 0;
}

int mostrarMerge()
{
    FILE* archMerge=fopen("Temporal.tmp","rb");
    if(!archMerge)
        return 1;

    Producto prod;
    printf("\n PRODUCTOS.TMP\n");
    fread(&prod,sizeof(Producto),1,archMerge);
    while(!feof(archMerge))
    {
        printf("cod: %-4s nombre: %-21s precio: %-5d stock: %d\n",prod.cod,prod.desc,prod.precio,prod.stock);
        fread(&prod,sizeof(Producto),1,archMerge);
    }
    fclose(archMerge);
    return 0;
}
