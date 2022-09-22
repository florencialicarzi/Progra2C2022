#ifndef ARCHIVOSDETEXTO_H_INCLUDED
#define ARCHIVOSDETEXTO_H_INCLUDED

#define ERR_ARCHIVO 1
#define TODO_OK 0
#define CANT_PRODS 10

typedef struct
{
    char cod[4];
    char des[15];
    int pre;
    int stock;

}Producto;

int imprimirArchivo(FILE* archivo, char tipoFormato);
int convertirTxtABin(const char* nombreTxt, char formato, const char* nombreBin);

#endif // ARCHIVOSDETEXTO_H_INCLUDED

