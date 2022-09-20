#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

typedef struct
{
    char cod[4];
    char desc[21];
    int precio;
    int stock;
}Producto;

typedef struct
{
    char cod[4];
    int cant;
}Movimiento;

int inicializarProdMov(void* prod, void* movs,int cantProd, int cantMov);
int actualizarProds(const char* productosA, const char* movimientosA);
void actProdNue(Movimiento* mov, FILE* archMovs, FILE* archProdsTmp);
int extraerYMostrarProdsYMovs();
int mostrarMerge();

#endif // MERGE_H_INCLUDED
