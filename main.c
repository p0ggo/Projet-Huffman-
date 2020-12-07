#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

// test des tcf A et B
int main()
{

    transfo_bin("input.txt");

    int a ;
    a = count_char("input.txt");
    printf("%d\n", a) ;

    /*test transfo ascii
    char codebin[] = "00000000";
    transfo_Ascii('a', codebin);
    printf("%s", codebin);*/

    return 0;
}


/*Partie 1, A
transformer un fichier Alice.txt avec des mots en fichier Output.txt avec des 0 ou 1
pour cela : lire le fichier Alice.txt
prendre les caractères un par un

transformer un caractère en code binaire
->avoir le code décimal
->le transformer en binaire

mettre la correspondance binaire du caratère dans un autre fichier (crée si non existant)
*/

/*Partie 1, B
afficher le nb de caractères dans un fichier .txt
normalement : alice.txt *8 = output.txt
*/
