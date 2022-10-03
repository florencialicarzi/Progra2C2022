#include <iostream>
#include "Stockitem.h"

using namespace std;

int main()
{
    Stockitem s1;
    s1.mostrar(); // va a mostrar el id = 0 , nombre = NULL, precio =0.0 y nArticulos = 0;
    cout << s1 << endl;
    Stockitem s2(1231,"Lavarropas",5676,30);
    cout<<s2<<endl;
    char nom[500]="Aspiradora";
    Stockitem s3(1256,nom, 12315,10);
    //s3++; // suma 1 a la cantidad del stock
    cout<<endl<<"Electrodomestico 3"<<endl;
    s3.mostrar();
    //cin>>s1;
    //cout<<s1;
    return 0;
}
