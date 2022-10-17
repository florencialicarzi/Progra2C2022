#ifndef TDA_COLA_ESTATICA_H_INCLUDED
#define TDA_COLA_ESTATICA_H_INCLUDED

#define TAM_COLA 100

typedef struct
{
    char vCola[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisp;

}Cola;

#endif // TDA_COLA_ESTATICA_H_INCLUDED
