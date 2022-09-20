#ifndef FUNCIONAPUNTERO_H_INCLUDED
#define FUNCIONAPUNTERO_H_INCLUDED

typedef int(*Cmp)(const void*, const void*); //Defino el tipo de comparacion como prototipo
                                            //Devuelve int (lo que usamos del signado)
typedef struct{
    int cod;
    char nombre[20] ;
    int precio;
    int stock;

}Producto;

//void ordenarSel(int* vec, int ce);
//int* buscarMenor(int* ini, int*fin);
void ordenarSelGenerico(void* vec, int ce,size_t tamElem, Cmp cmp);
void* buscarMenorGenerico(void* ini, void*fin, size_t tamElem, Cmp cmp);
void intercambiar(void* elem1, void*elem2, size_t tamElem);
int cmpProdCod(const void* p1, const void* p2);
int cmpProdStockCod(const void* p1, const void* p2);

#endif // FUNCIONAPUNTERO_H_INCLUDED
