#ifndef NODOA_H_INCLUDED
#define NODOA_H_INCLUDED

typedef struct SNodoA
{
    void* elem;
    size_t tamElem;
    struct SNodoA hIzq;
    struct SNodoA hDer;
}

#endif // NODOA_H_INCLUDED
