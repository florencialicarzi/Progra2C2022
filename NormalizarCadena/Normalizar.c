#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Normalizar.h"


void normalizarCad(char* cad)
{
    char* borrar;
    int i;

    while(*cad)
    {
        if(isalpha(*cad)||((*cad == ' ')&&(*(cad+1) == ' '))) // Si no es alfanumerico lo saco (a menos que sea un espacio).
        {
            *cad = toupper(*cad);
            if(isalpha(*(cad-1)))
                   *cad=tolower(*cad);
            cad++;
        }
        else
        {
            borrar = cad;

            for(i=0; i<=strlen(cad); i++) // Voy hasta el strlen, como avanzo el puntero de mi cadena, cada vez va a retornar un valor menor, sabiendo donde cortar.
            {
                memcpy(borrar, borrar+1, 1);
                borrar++;
            }
        }
    }
}
