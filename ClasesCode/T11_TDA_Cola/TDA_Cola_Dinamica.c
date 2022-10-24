void crearCola(Cola* pc)
{
    pc->frente = pc->fondo=NULL;
}

bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem,tamElem);
    if(!nue)
        return false;

    if(!pc->fondo)
        pc->frente=nue //(3)
    else
        pc->fondo->sig=nue; //(1)

    pc->fondo = nue;//(2)

    return true;
}

bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(!pc->frente)
        return false;

    Nodo* nae = pc->frente; //(1)
    pc->frente= nae->sig; //(2)

    if(!pc->frente)
        pc->fondo=NULL; //(3)

    destruirNodo(nae,elem,tamElem); //void
    return true;
}

bool verFrenteDeCola(const Cola* pc, void* elem, size_t tamElem)
{
    if(!pc->frente)
        return false;

    const Nodo* frente = pc->frente; // el const solo si da warning
    memcpy(elem, frente->elem, min(tamElem, frente->tamElem));

    return true;
}

bool colaVacia(const Cola* pc)
{
    return !pc->frente;
}

bool colaLlena(const Cola* pc, size_t tamElem)
{
    void* nodo= malloc(sizeof(Nodo));
    void* elem= malloc(tamElem);
    free(nodo);
    free(elem);
    return !nodo || !elem;
}

void vaciarCola(Cola* pc)
{
    Nodo* frenteN = pc->frente
    Nodo* nae;
    while(frenteN)
    {
        nae= frenteN;
        frenteN = nae->sig; //en el ultimo pone Null sobre frenteN, pero no es pc->frente
        free(nae->elem);
        free(nae);
    }
    pc->fondo=NULL;
    pc->frente=NULL; //por eso lo pongo aca abajo

    return true;
}

/////////////////////
void destruirNodo(Nodo* nae,void* elem,size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}


void ordenarLista(Lista* pl, Cmp cmp)
{
    Lista lOrd= NULL;
    Lista* plOrd;

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
