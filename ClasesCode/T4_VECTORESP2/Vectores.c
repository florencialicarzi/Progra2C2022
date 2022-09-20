#include <stdio.h>
#include <conio.h>

void elegirCantPosiciones(int* tam)
{

    printf("Tam del vector de enteros:");
    scanf("%d", tam);
}

void cargarVector(int* vec, const int* tam, int* cantElem)
{
    int i=0, flag=0;
    printf("Cargar un vector de %d posiciones:\n", *tam);
    do
    {
      printf("tam %d: ",i);
      scanf("%d", vec+i);
      flag = (*(vec+i) == 0)? 1 : 0;
      i++;
    }while(flag==0 && i< *tam);
    *cantElem = (flag==0)? i: i-1;
}

void mostrarVector(int* vec, const int* tam, const int* cantElem)
{
    int i=0, flag=0;
    puts("VECTOR ACTUAL: ");
    do
    {
      printf("%d ", *(vec+i));
      flag = (*(vec+i) == 0)? 1 : 0;
      i++;
    }while(flag==0 && i< *cantElem);

    printf("\nTam del vector: %d | Cantidad de elementos: %d \n\n", *tam, (flag==0)? i: i-1);
}

int consultaVecLleno(const int* tam, const int* cantElem)
{
    if((*tam) == (*cantElem))
    {
        puts("El vector ya se encuentra lleno\nPulse cualquier tecla para volver al menu...");
        getch();
        return 1;
    }
    return 0;
}

void desplazarIzqDH(int* vec, int* desde, int* hasta)
{
    int i;
    for(i=(*desde); i<(*hasta); i++)
        *(vec+i)= *(vec+i+1);
}

void desplazarDerDH(int* vec, int* desde, int* hasta)
{
    int i;
    for(i=(*hasta); i>(*desde); i--)
        *(vec+i)= *(vec+i-1);
}

//Ejercicio 22 Desarrollar una funci�n que inserte un elemento en un arreglo de enteros, dada la posici�n de inserci�n.
void insertarEnPos(int* vec, const int* tam, int* cantElem, int* posInsertar, int* elem)
{

    if(consultaVecLleno(tam,cantElem))
        return;

    puts("INSERTAR EN POSICION\n");
    printf("Ingrese la posicion:");
    scanf("%d", posInsertar);
    printf("\nIngrese el valor a insertar:");
    scanf("%d", elem);

    desplazarDerDH(vec,posInsertar,cantElem);

    *(vec+(*posInsertar)) = *elem;

    *cantElem+=1;
}

//Ejercicio 23 Desarrollar una funci�n que inserte un elemento en un arreglo de enteros, ordenado en forma ascendente, de forma de no alterar el orden
void insertarEnOrden(int* vec, const int* tam, int* cantElem, int* elem)
{
    int i=0;

    if(consultaVecLleno(tam,cantElem))
        return;

    printf("\nIngrese el valor a insertar:");
    scanf("%d", elem);

    while(*elem >= *(vec+i) && i<*cantElem)
        i++;

    desplazarDerDH(vec,&i, cantElem);

    *(vec+i) = *elem;
    *cantElem+=1;
}

//Ejercicio 24 Desarrollar una funci�n que elimine el elemento que ocupa una determinada posici�n de un arreglo de enteros.
void eliminarEnPos(int* vec, int* tam, int* cantElem, int* posEliminar)
{
    int rep=0;
    mostrarVector(vec,tam,cantElem);
    printf("Ingrese una posicion del 0 al %d:", *cantElem-1);
    do{
        if(rep==1)
            printf("Valor invalido, vuelva a intentarlo ->");
        scanf("%d", posEliminar);
        rep=1;
    }while(*posEliminar<0 || *posEliminar>= *cantElem);


    desplazarIzqDH(vec,posEliminar,cantElem);

    *cantElem-=1;
}

void eliminarPrimerAparicionX(int* vec, int* tam, int* cantElem, int* elem)
{
    int i=0;
    mostrarVector(vec,tam,cantElem);
    printf("\nIngrese el elemento a eliminar:");
    scanf("%d", elem);

    while(*(vec+i)!= *elem && i< (*cantElem))
         i++;


    if(*(vec+i)== *elem)
    {
        desplazarIzqDH(vec,&i,cantElem);
        *cantElem -=1;
    }else
    {
        puts("No se encontro ese elemento");
    }

}

void eliminarTodosLosX()
{

}


