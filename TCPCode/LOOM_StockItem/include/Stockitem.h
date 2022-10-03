#ifndef STOCKITEM_H
#define STOCKITEM_H

using namespace std;

class Stockitem
{
    private:
        int id;
        char* nombre;
        float precio;
        int nArticulos;

    public:
        Stockitem();
        Stockitem(int id,char* nombre,float precio,int nArt);
        void mostrar();

        friend ostream& operator <<(ostream& sal, const Stockitem& Stockitem);
};

#endif // STOCKITEM_H
