#include <stdio.h>
#include <stdlib.h>
#include "Merge.h"

int main()
{
    Producto prod[] = {
        {"ANA", "Anana",100,200},
        {"BAN", "Banana",120,250},
        {"CER", "Cereza",200,300},
        {"DUR", "Durazno",150,1000},
        {"NAR", "Naranja",120,500},
        {"ZAN", "Zandia",150,350}
    };

    Movimiento movs[] = {
        {"BAN",50},
        {"BAN",-20},
        {"DUR",-100},
        {"DUR",-150},
        {"MAN",100},
        {"MAN",160},
        {"NAR",-50}
    };
    int cantProd= (sizeof(prod))/(sizeof(Producto));
    int cantMov=(sizeof(movs))/(sizeof(Movimiento));
    inicializarProdMov(&prod, &movs, cantProd, cantMov);
    extraerYMostrarProdsYMovs();
    actualizarProds("Productos.dat","Movimientos.dat");

    return 0;
}
