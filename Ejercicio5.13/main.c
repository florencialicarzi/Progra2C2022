#include <stdio.h>
#include <stdlib.h>
#include "Ej5.13.h"
#define archalea "archalea.dat"

#define archal1 "archal1.dat"
#define archal2 "archal2.dat"
#define archal3 "archal3.dat"

#define archalT1 "archal1.txt"
#define archalT2 "archal2.txt"
#define archalT3 "archal3.txt"

#define archtex1 "archtex1.txt"
#define archtex2 "archtex2.txt"
#define archtex3 "archtex3.txt"

#define archord1 "archord1.txt"
#define archord2 "archord2.txt"
#define archord3 "archord3.txt"

#define archord "archord.txt"

int main()
{
    puts("\n----------------------------------GENERAR ARCH RAND-----------------------------------------");
    generarBinRand(archalea);
    mostrarArchBin_esp(archalea);

    puts("\n----------------------------------RAND BIN TRIFURCADO---------------------------------------");
    triArchBin(archal1,archal2,archal3,archalea);
    puts("\nArch1 bin");
    mostrarArchBin_esp(archal1);
    puts("\nArch2 bin");
    mostrarArchBin_esp(archal2);
    puts("\nArch3 bin");
    mostrarArchBin_esp(archal3);

    puts("\n----------------------------------RAND TXT TRIFURCADO---------------------------------------");
    generarBinATxt(archal1,archalT1);
    generarBinATxt(archal2,archalT2);
    generarBinATxt(archal3,archalT3);

    puts("\nArch1 txt");
    mostrarArchTxt_esp(archalT1);
    puts("\nArch2 txt");
    mostrarArchTxt_esp(archalT2);
    puts("\nArch3 txt");
    mostrarArchTxt_esp(archalT3);

    puts("\n-----------------------------------OFUSCAR TXT TRI-------------------------------------------");
    ofuscarNum(archalT1,archtex1,17);
    ofuscarNum(archalT2,archtex2,27);
    ofuscarNum(archalT3,archtex3,37);

    mostrarArchTxt_esp(archtex1);
    puts("");
    mostrarArchTxt_esp(archtex2);
    puts("");
    mostrarArchTxt_esp(archtex3);

    puts("\n----------------------------------ORDENAR TXT TRI--------------------------------------------");
    ordenarArchText(archtex1,archord1,91,3);
    ordenarArchText(archtex2,archord2,91,3);
    ordenarArchText(archtex3,archord3,91,3);

    mostrarArchTxt_esp(archord1);
    puts("");
    mostrarArchTxt_esp(archord2);
    puts("");
    mostrarArchTxt_esp(archord3);

    puts("\n----------------------------------JUNTAR ORDENADO---------------------------------------------");
    juntarTxts(archord,archord1,archord2,archord3);
    mostrarArchTxt_esp(archord);


    return 0;
}
