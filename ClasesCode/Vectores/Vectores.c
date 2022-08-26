#include <stdio.h>

void elegirCantPosiciones(int* cant)
{

    printf("Cantidad de posiciones del vector de enteros:");
    scanf("%d", cant);
}

void cargarVector(int* vec, const int* cant)
{
    int i=0, flag=0;
    printf("Cargar un vector de %d posiciones:\n", *cant);
    do
    {
      scanf("%d", vec+i);
      flag = (*(vec+i) == 0)? 1 : 0;
      i++;
    }while(flag==0 && i< *cant);
}

void mostrarVector(int* vec, const int* cant)
{
    int i=0, flag=0;
    puts("VECTOR ACTUAL: ");
    do
    {
      printf("%d ", *(vec+i));
      flag = (*(vec+i) == 0)? 1 : 0;
      i++;
    }while(flag==0 && i< *cant);

    printf("\nCantidad de Posiciones: %d, Posiciones ocupadas: %d \n\n", *cant, i);
}

//Ejercicio 22 Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.
void insertarEnPos()
{

}

void insertarEnOrden()
{

}

void eliminarEnPos()
{

}

void eliminarPrimerAparicionX()
{

}

void eliminarTodosLosX()
{

}


