#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#define MENU_MSJ "MENU\n\n" \
                 "A- Cargar vector\n" \
                 "B- Insertar en posicion n\n" \
                 "C- Insertar en orden\n" \
                 "D- Eliminar en n posicion\n"\
                 "E- Eliminar primera aparicion de X\n"\
                 "F- Eliminar todas las apariciones de X\n"\
                 "S- Salir\n"\
                 "--->"

#define MENU_OPC "ABCDEFSabcdefs"

void elegirCantPosiciones(int* pos);
void cargarVector(int* vec, const int* pos, int* cantElem);
void mostrarVector(int* vec, const int* pos, const int*);
int consultaVecLleno(const int* pos, const int* cantElem);
void desplazarIzqDH(int* vec, int* desde, int* hasta);
void desplazarDerDH(int* vec, int* desde, int* hasta);

void insertarEnPos(int* vec, const int* pos, int* cantElem,  int*,  int*);
void insertarEnOrden(int* vec, const int* pos, int* cantElem, int*);
void eliminarEnPos(int* vec, const int* pos, int* cantElem,  int*);
void eliminarPrimerAparicionX(int* vec, int* tam, int* cantElem,  int* elem);
void eliminarTodosLosX();


#endif // VECTORES_H_INCLUDED
