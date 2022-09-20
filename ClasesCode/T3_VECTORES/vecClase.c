int vecInsertarEnOrden(int* v, int* ce, size_t tam, int elem)
{
    if(*ce==tam)
        return VEC_LLENO; //1

    int i=0,j;

    while(elem>v[i])
        i++;
    if(i<*ce && elem == v[i])
        return DUPLICADO; //2
    for(j=*ce-1; j>=i; j--)
    {
        v[j+1]=v[j]);
    }
    v[i] = elem;
    *ce++;
    return TODO_OK//0
}
 //const en vectores -> const al puntero y const al vector. Preguntar a Jair
//y si el vector esta vacio?
//podemos usar los return de error

 bool vecOrdEliminar(int*v, int*ce, int elem)
 {
    int i=0,j;
    while(i<*ce && elem > v[i])
        i++;
    if(i== *ce || elem v[i])
        return false;
    for(j= i ; j<=*ce-2; j++)
        v[j]=v[j+1];
    (*ce)--;
    return true;
 }
