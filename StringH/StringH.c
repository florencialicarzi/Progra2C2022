#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StringH.h"

//STRING.H

size_t mi_strlen(const char* cad)
{
    size_t cont=0;
    while(*cad)
    {
        cont++;
        cad++;
    }

    return cont;
}

char* mi_strcpy(char* s1, const char* s2)
{
    char* ps= s1;
    while(*s2)
    {
        *ps= *s2;
        ps++;
        s2++;
    }

    *ps='\0';
    return s1;
}

int mi_strcmp( const char* s1, const char* s2)
{
    int resta=0;
    while(*s1 || *s2)
    {
        if(*s1 != *s2)
        {
            resta= *s1-*s2;
            return (resta>0)? 1: -1;
        }
        s1++;
        s2++;
    }

    return 0;

}

int mi_strncmp( const char* s1, const char* s2, size_t n)
{
    int resta=0;
    while((*s1 || *s2) && n>0 )
    {
        if(*s1 != *s2)
        {
            resta= *s1-*s2;
            return (resta>0)? 1: -1;
        }

        s1++;
        s2++;
        n--;
    }
    return 0;
}

int mi_strcmpi(const char* cad1, const char* cad2)
{

    int resta = 0;

    while(*cad1 || *cad2)
    {
        if(tolower(*cad1) != tolower(*cad2))
        {
            resta = tolower(*cad1) - tolower(*cad2);
            return (resta > 0) ? 1 : -1;
        }

        cad1++;
        cad2++;
    }

    return resta;

}


int mi_strnicmp( const char* s1, const char* s2, size_t n)
{
    int resta=0;
    while((*s1 || *s2) && n>0 )
    {
        if(tolower(*s1) != tolower(*s2))
        {
            resta= tolower(*s1)-tolower(*s2);
            return (resta>0)? 1: -1;
        }

        s1++;
        s2++;
        n--;
    }
    return 0;
}

char* mi_strcat(char* cad1, const char *cad2)
{
    char* pi = cad1;

    while(*cad2)
    {
        while(*cad1)
            cad1++;

        *cad1 = *cad2;
        cad1++;
        cad2++;
    }

    cad1 = '\0';

    return pi;

}

char* mi_strchr(char*s, int c)
{
    while(*s)
    {
        if(*s==(unsigned char)c)
            return s;
        s++;
    }

    return NULL;
}

char* mi_strrchr(char*s, int c)
{
    char* pi = s;

    while(*s)
        s++;

    s--;

    while(pi != s)
    {
        if(*s==(unsigned char)c)
            return s;
        s--;
    }

    return NULL;
}

char* mi_strstr(const char* s1, const char* s2)
{
    int cont=0;

    while(*s1) //si strlen de lo que sobra de s1 es mas chico que s2, tmb corta
    {
        if(*s1==*s2)
        {
            s1++;
            s2++;
            cont++;

            if(!(*s2))
                return (char*)s1-cont;
        }
        else
        {
            s1-=(cont-1);
            s2-=(cont);
            cont=0;

        }
    }

    return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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
