#include <iostream>
#include "Stockitem.h"

using namespace std;

Stockitem::Stockitem()
{
    id=0;
    nombre= "NULL";
    precio= 0.0;
    nArticulos=0;
}

//memoria dinamica para el nombre
Stockitem::Stockitem(int _id, char* _nombre, float _precio, int _nArt)
{
    id=_id;
    nombre=_nombre;
    precio=_precio;
    nArticulos=_nArt;
}

void Stockitem::mostrar()
{
    cout<<"Id:"<<id<<" Nombre:"<<nombre<<" Precio:"<<precio<<" nArticulo:"<<nArticulos<<endl;
}

ostream& operator <<(ostream& sal, const Stockitem& Stockitem)
{
    sal<<Stockitem.id<<'\t';
    sal<<Stockitem.nombre<<'\t';
    sal<<Stockitem.precio<<'\t';
    sal<<Stockitem.nArticulos<<'\t';

    return sal;
}



