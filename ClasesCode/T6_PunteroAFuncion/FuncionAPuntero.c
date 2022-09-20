#include <stdio.h>
#include <string.h>
#include "FuncionAPuntero.h"

//GENERICOS
void ordenarSelGenerico(void* vec, int ce, size_t tamElem, Cmp cmp)
{
    void* ult= vec+(ce-1)*tamElem;//Multiplico por el tamaño
    void* menor;
    for(void* i=vec;i<ult;i+=(tamElem))//que incremente el tamaño del elemento
    {
        menor=buscarMenorGenerico(i,ult, tamElem,cmp);
        if(menor!= i)
        {
            intercambiar(menor,i,tamElem);
        }

    }
}

void* buscarMenorGenerico(void* ini, void* fin, size_t tamElem, Cmp cmp) //puedo meter lo del typedef del Cmp aca pero es una paja
{
    void* menor=ini;
    for(void* i=ini+tamElem;i<fin;i+=tamElem) //ini+1 = ini+tamElem
        //cmp es puntero a funcion, puedo comparar por lo que quiera.
        if(cmp(i,menor)<0)// 0:iguales +:i es mayor -:i es menor
            menor=i;


    return menor;
}

void intercambiar(void* elem1, void*elem2, size_t tamElem)
{
    //Al ser void* no se puedo usar el "=", necesito usar memcpy
    char aux[tamElem]; //char pq tiene 1 byte justo para el tamElem
    memcpy(aux,elem1,tamElem); //aux=*elem1;
    memcpy(elem1,elem2,tamElem); //*elem1 = *elem2
    memcpy(elem2,aux,tamElem); //*elem2= aux;
}

