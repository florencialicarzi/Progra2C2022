#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TDA_Pila.h"

char* sumar(const char* num1, const char* num2)
{
    Pila pila1, pila2, pilaSuma;
    int dig1, dig2, digSuma, acarreo=0;
    char dig1C, dig2C, digSumaC;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pilaSuma);

    //Veo la longitud de cada numero
    int tamNum1 = strlen(num1);
    int tamNum2 = strlen(num2);
    int tamSuma = tamNum1 > tamNum2? tamNum1: tamNum2;

    //Agrego los ceros a la menor
    int restaTams = tamNum1 - tamNum2;
    int cantCeros = abs(restaTams);
    bool pilaMenor = restaTams < 0;

    apilarCeros(pilaMenor? &pila1 : &pila2, cantCeros);

    //Armo las pilas de los numeros a sumar
    apilarNumero(&pila1, num1);
    apilarNumero(&pila2, num2);

    while(!pilaVacia(&pila1))
    {
        //desapilo
        desapilar(&pila1, &dig1C, sizeof(char));
        desapilar(&pila2, &dig2C, sizeof(char));

        //convierto de ascii a int/binario
        dig1 = dig1C - '0';
        dig2 = dig2C - '0';

        //Resultado y acarreo
        digSuma= dig1+dig2+acarreo;
        acarreo= digSuma/10;
        digSuma %= 10;

        //Vuelvo a convertir el res para apilar
        digSumaC = digSuma + '0';
        apilar(&pilaSuma, &digSumaC, sizeof(char));
    }

    //Si quedo acarreo lo apilo
    if(acarreo == 1)
    {
        digSumaC= '1';
        apilar(&pilaSuma, &digSumaC, sizeof(char));
        tamSuma++;
    }

    char* suma = malloc(tamSuma +1); //uno para el caracter nulo

    if(!suma)
    {
        puts("No se pudo reservar memoria");
        return NULL;
    }

    desapilarNumero(suma,&pilaSuma);
    return suma;

}

bool apilarCeros(Pila* pila, int cantCeros)
{
    int cerosApilados = 0;
    char cero= '0';
    while(cerosApilados< cantCeros)
    {
        //Necesito pasarle una dir, no puedo mandar &'0', por eso la variable cero
        if(!apilar(pila, &cero , sizeof(char)))
            return false;
        cerosApilados++;
    }
    return true;
}

bool apilarNumero(Pila* pila, const char* num)
{
    const char* i = num;
    while(*i)
    {
        if(!apilar(pila,i,sizeof(char)))
            return false;
        i++;
    }
    return true;
}

bool desapilarNumero(char* num, Pila* pila)
{
    char* i= num;
    char digitoC;
    while(!pilaVacia(pila))
    {
        desapilar(pila, &digitoC, sizeof(char));
        *i= digitoC;
        i++;
    }
    *i='\0';

    return true;
}
