#include "vectores.h"


int llenarVector(int *vec)
{
    int i=0, num;

    printf("Cargue valores (%i como maximo) al vector (ingrese 0 para salir): ", TAM);
    scanf("%i", &num);

    while(i<TAM-1 && num!=0)
    {
        *vec = num;
        vec++;
        i++;
        scanf("%i", &num);
    }

    return i;
}

booleano insEnVector(int *vec, int pos, int elem, const int cantElem)
{
    int *i;

    if(pos>cantElem+1 || pos<1)
        return ERROR;

    if(cantElem+1<=TAM && pos==cantElem+1)
    {
        *(vec+cantElem) = elem;
        cantElem++;
        return INSERTADO;
    }


    for(i=vec+TAM; i>vec+pos-1; i--)
    {
        *i = *(i-1);
    }
    *(vec+pos-1) = elem;

    return INSERTADO;
}


//booleano insEnVecOrdenado(int *vec, int elem, int cantElem)
//{
//    int *i;
//    i = vec;
//}
