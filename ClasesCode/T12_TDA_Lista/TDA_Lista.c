int insertarEnListaOrdSinDup(Lista *pl, const void*elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    while(*pl&&(cmp(elem,(*pl)->elem))>0) //cuidao segmentation fault
        pl=&(*pl)->sig;

    if(*pl&&cmp(elem,(*pl)->elem)==0)
    {
        actualizar((*pl)->elem, elem);
        return DUPLICADO;
    }

    Nodo* nue= crearNodo(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig= *pl;
    *pl=nue;

    return TODO_OK;
}

int eliminarDeListaOrdXValor(Lista* pl, void* elem, size_t tamElem, Cmp cmp) //elem me trae el dato pero ahi devuelvo el nodo
{
    if(!*pl)
        return LISTA_VACIA;

    while(*pl&& cmp(elem,(*pl)->elem)>0)
        pl = &((*pl)->sig);

    if(!*pl || !(cmp(elem,(*pl)->elem)<0))
        return NO_EXISTE;

    Nodo* nae = *pl;
    *pl= nae->sig;

    destruirNodo(nae,elem,tamElem);
    return TODO_OK
}

//Insertar en lista desordenada con/sin dup
//Insertar en pos con/sin dup
//Insertar inicio
//Insertar final
//eliminar en pos
//eliminar primero
//eliminar ultimo
//buscar lista ordenada
//buscar lista desordenada
//Ordenar lista (con lista auxiliar con metodos)

void ordenarListaPan(Lista* pl, Cmp cmp)
{
    Lista lOrd= NULL;
    Lista* plOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo=*pl;
        *pl= nodo->sig;
        plOrd= &plOrd;

        while(*plOrd && cmp(nodo->elem, (*plOrd)->elem >0)
              plOrd = &(*plOrd)->sig;

        nodo->sig = *plOrd;
        *plOrd=nodo;
    }

    *pl=lOrd;
}


int comparar(const void* dato1, const void* dato2)
{
    return *(int*)dato1 - *(int*)dato2;
}

Lista* buscarMenor(Lista* aux, Lista* menor, Cmp cmp)
{

    while((*aux)->sig) // Mientras haya siguiente, si hay uno solo esta ordenada.
    {

        if(cmp((*menor)->elem, (*aux)->sig->elem) > 0)
            menor = &(*aux)->sig;

        aux = &(*aux)->sig;

    }

    printf("\nMenor: %d", *(int*)(*menor)->elem);
    return menor;
}

void ordenarListaSeleccion(Lista* pl, Cmp cmp)
{

    Lista* menor = pl;
    Lista* aux = pl;

    if(*pl == NULL)
        return;


    while((*pl)->sig) // Mientras haya siguiente, si hay uno solo esta ordenada.
    {

        menor = buscarMenor(aux, menor, cmp);

        Nodo* pri = *menor;

        *menor = pri->sig;

        pri->sig = *pl;

        *pl = pri;

        pl = &(*pl)->sig;

        menor = pl;
        aux =pl;

    }
}
