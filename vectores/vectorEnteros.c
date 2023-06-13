#include <stdio.h>
#include <stdlib.h>

void mostrarVectorEnteros(int *vec, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("%d ", *vec);
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

void insertarVecPos(int *vec, int elem ,int pos, int *ce, int tam)
{

    if(tam< (*ce+1))
    {
        puts("NO hay lugar para insercion");
        return;
    }

    int *pf = vec+(*ce-1);

    vec+=(pos-1);

    if(vec!= pf+1) //si la insersion no es al final corro
    {
        while(pf != vec)
        {
            *(pf+1) = *pf;
            pf--;
        }

        *(pf+1) = *pf;

    }
    *vec = elem;
    *ce+=1;
}

void insertarVecOrd(int *vec, int elem, int *ce, int tam)
{
   if(tam<= (*ce+1))
    {
        puts("NO hay lugar para insercion");
        return;
    }

    int *pf = vec+(*ce-1);

    while((elem >= *vec) && ((pf+1) != vec))
    {
        vec++;
    }

    if(vec!= pf+1) //si la insersion no es al final
    {
        while(pf != vec)
        {
            *(pf+1) = *pf;
            pf--;
        }

        *(pf+1) = *pf;

    }
    *vec = elem;
    *ce+=1;

}

void eliminarEnVectorPos(int *vec,int pos, int *ce)
{
    int i=0;
    if(pos>*ce)
    {
        puts("la posicion es invalida");
        return;
    }

    vec+=(pos-1);
    do{
        *vec= *(vec+1);
        vec++;
        i++;
    }while(i<(*ce)-pos);

    (*ce)-=1;
}

void eliminarPrimerAparicionElem(int *vec, int elem ,int *ce)
{
    int i=0;
    while(*(vec)!=elem && i<(*ce))
    {
        i++;
        vec++;
    }

    if(*(vec)==elem)
        eliminarEnVectorPos(vec-i,(i+1),ce);
    else
        puts("No existe tal elemento");
}

void eliminarAparicionesElem(int *vec, int elem ,int *ce)
{
   int *pe=vec+(*ce)-1, i=0;

   do
   {
       if(*pe == elem)
       {
           if(pe== vec+(*ce)-1)
           {
               *pe=0;
           }
           else
           {
                while(pe!=vec+(*ce))
                {
                  *pe=*(pe+1);
                  pe++;
                  i++;
                }
                pe-=i; //esto esta medio rancio, podria hacer 3 punteros(?
                i=0;
           }
           *ce-=1;
       }
       pe-=1;
   }while(pe>=vec); //ta bien(?

}
