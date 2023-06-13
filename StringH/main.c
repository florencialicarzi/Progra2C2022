#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringH.h"

int main()
{
    char cada[50] = "el sol solo sale";
    char cadb[] = "solo";

    char cad[50] = "el sol solo sale";
    char cad2[] = "solo";

    printf("%s  \n%s \n", cad,cad2);
    puts("");
    printf("Strlen: %d   mi_strlen: %d \n", (int)strlen(cad), (int)mi_strlen(cad));

    printf("Strcmp: %d  mi_strcmp: %d \n", strcmp(cad,cad2), mi_strcmp(cad,cad2));
    printf("Strcmpi: %d  mi_strcmpi: %d \n", strcmpi(cad,cad2), mi_strcmpi(cad,cad2));
    printf("Strncmp: %d  mi_strncmp: %d \n", strncmp(cad,cad2,3), mi_strncmp(cad,cad2,3));
    printf("Strnicmp: %d  mi_strnicmp: %d \n", strnicmp(cad,cad2,3), mi_strnicmp(cad,cad2,3));

    printf("Strcat: %s  mi_strcat: %s \n", strcat(cada,cadb), mi_strcat(cad,cad2));

    printf("Strchr: %s mi_strchr: %s \n", strchr(cadb,'b'), mi_strchr(cad2,'b'));

    printf("Strrchr: %s mi_strrchr: %s \n", strrchr(cadb,'o'), mi_strrchr(cad2,'o'));

    printf("Strcpy: %s  mi_strcpy: %s \n", strcpy(cada,cadb), mi_strcpy(cad,cad2));

    printf("mi_Strstr:%s", mi_strstr(cad,cad2));
    return 0;
}


//    char cad[] = "H*oLa,  CoMO  e 3ST$aS";
//    printf("%s\n", cad);
//
//    normalizarCad(cad);
//
//    printf("%s", cad);
//char cad[] = "Hola como estas todo bien";
//    char cad2[] = "Todo bien";
