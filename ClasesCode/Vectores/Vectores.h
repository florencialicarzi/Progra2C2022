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

void elegirCantPosiciones(int* cant);
void cargarVector(int* vec, const int* cant);
void mostrarVector(int* vec, const int* cant);
void insertarEnPos();
void insertarEnOrden();
void eliminarEnPos();
void eliminarPrimerAparicionX();
void eliminarTodosLosX();


#endif // VECTORES_H_INCLUDED
