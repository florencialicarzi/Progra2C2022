#include <stdio.h>
#include <stdlib.h>
#include "ArchivosDeTexto.h"

int main()
{
    FILE* archProds = fopen("Productos.dat", "wb");
    if(!archProds)
    {
        printf("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }

    Producto arrProds[CANT_PRODS] =
    {
        {"PAP", "Papa", 120.50, 200},
        {"ZAN", "Zanahoria", 80.50, 100},
        {"LEC", "Lechuga", 50.50, 50},
        {"TOM", "Tomate", 70.50, 150},
        {"CEB", "Cebolla", 60.50, 250},
        {"MOR", "Morron", 90.50, 300},
        {"NAR", "Naranja", 100.50, 400},
        {"PER", "Pera", 110.50, 500},
        {"MAN", "Manzana", 120.50, 600},
        {"BAN","Banana", 130.50, 700},
    };

    fwrite(arrProds, sizeof(Producto), CANT_PRODS, archProds);
    fclose(archProds);

    /*leer archivo
    puts("Archivo antes de actualizar:");
    int ret = imprimirArchivo();

    if(ret != TODO_OK)
        return ret;

    actualizarArchivo("Productos.dat");*/

    return 0;
}
