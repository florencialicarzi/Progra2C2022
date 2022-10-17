#define TDA_COLA_EST
#include "TDA_Cola.h"

void crearCola(Cola*pc)
{
    pc->frente = 0;
    pc->fondo =0;
    pc->tamDisp= TAM_COLA;
}

bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > pc->tamDisp)
        return false;

    //COPIO TAMAÑO
    copiarDatoEnCola(pc, &tamElem, sizeof(size_t));
        //Hago que pc se mueva dando la vuelta si es necesario hasta la posicion del resto
    pc->fondo= (pc->fondo + sizeof(size_t)) % TAM_COLA;

    //COPIO ELEMENTO
    copiarDatoEnCola(pc, elem, tamElem));
    pc->fondo= (pc->fondo + sizeof(size_t)) % TAM_COLA;

    //Disminuyo el tamaño disponible
    pc->tamDisp -= tamElem + sizeof(size_t);
}

bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisp==TAM_COLA) //esta vacia?
        return false;

    size_t tamElemEncolado;

    //Desencolo tamaño
    copiarDatoDeCola(pc, &tamElemEncolado, sizeof(size_t));
    pc->frente = (pc->frente + sizeof(size_t))% TAM_COLA; //Verifica si frente no dio vuelta al desencolar los restos

    //Desencolo elemento
    copiarDatoDeCola(pc, elem, min(tamElem, tamElemEncolado));
    pc->frente = (pc->frente + sizeof(size_t))% TAM_COLA;

    //Agrego el espacio desencolado a tamDisp
    pc->tamDisp += tamElemEncolado + sizeof(size_t);

    return true;
}
bool verTopeDeCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc);
void vaciarCola(Cola* pc);

//
void copiarDatoEnCola(Cola*pc, const void* dato, size_t tamDato)
{
    size_t cantACopiar= tamDato;
    //Me fijo si puedo copiar todo en una parte o si necesito dos
    size_t cantContigua= pc->fondo >= pc->frente? TAM_COLA-(pc->fondo) : pc->frente - pc->fondo;

    memcpy(pc->vCola + pc->fondo, dato, cantContigua);
    cantACopiar-=cantContigua;

    if(cantACopiar>0 //Si hay un resto o copio en "Frente"
        memcpy(pc->vCola, (char*)dato+cantContigua, cantACopiar);
                        //la direccion de inicio del elemento + lo que ya copie, me da el inicio del resto de elem
                        //casteo pq parece que no le gusta aritmetica de punteros void, pedantic forro
}
