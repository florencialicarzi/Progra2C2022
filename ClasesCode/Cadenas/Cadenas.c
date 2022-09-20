#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Cadenas.h"

//void mostrarCadena()
//{
//    int i=0, flag=0;
//    puts("VECTOR ACTUAL: ");
//    do
//    {
//      printf("%d ", *(vec+i));
//      flag = (*(vec+i) == 0)? 1 : 0;
//      i++;
//    }while(flag==0 && i< *cantElem);
//
//    printf("\nTam del vector: %d | Cantidad de elementos: %d \n\n", *tam, (flag==0)? i: i-1);
//}

bool esPalindromo(const char* cad)
{
    const char* izq= cad;
    const char* der= cad + strlen(cad) -1; //strlen no cuenta caracter nulo
    while(izq<der && tolower(toSinTilde(*izq))==tolower(toSinTilde(*der))) //tolower es copia, convive con const.
    {
        izq++;
        der--;
    }
    return izq>=der; //1: es palindromo 0:no lo es
}

bool sonAnagramas(const char* cad1, const char* cad2)
{

}

char ordenarCadena(char cad, int cantElem) //con seleccion
{
    int i,j, cantEOrd=0;
    char* pc= &cad;
    char aux;
    char* menor= pc;

    for(j=0; j<cantElem; j++)
    {
        for(i=0; i<cantElem; i++) //(pc; ;pc++)
        {
            if(*(pc+i)<*menor)
                menor= pc+i;
        }
        aux = *(pc+cantEOrd);
        *(pc+cantEOrd)= *menor;
        *(menor) = aux;

        cantEOrd++;
    }
        printf("%s", cad);

    return cad;
}
//Hacer todo string.h a manito. (strlen, strcmp, strcpy con fin de cadena)
char toSinTilde()
{

}

char miToLower(char c)
{
    if(c>='A' && c<='z')
        return c+('a'-'A');
    return c;
}

