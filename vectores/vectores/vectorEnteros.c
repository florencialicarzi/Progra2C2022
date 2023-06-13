#include <stdio.h>
#include <stdlib.h>

void mostrarVector(int *vec, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("%d", *vec);
        vec++;
    }
}

void compararVectores(int *vec1, int *vec2, int ce)
{
    while(ce != 0)
    {

        if(*(vec1) == *(vec2))
        {
            vec1++;
            vec2++;
        }

        else
        {
            printf("No son iguales");
            return;
        }

        ce--;
    }

}

void insertarVecPos(int *vec, int elem ,int pos, int ce)
{

/*    if(sizeof()/sizeof(int) <= (ce+1)) //Condicion de corte inicial no funca.
        return; */

    int i, *pf = vec+(ce-1);

    vec+=(pos-1);

    while(pf != vec)
    {
        *(pf+1) = *pf;
        pf--;
    }

    *(pf+1) = *pf;
    *vec = elem;


}

