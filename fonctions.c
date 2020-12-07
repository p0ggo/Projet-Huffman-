#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

// transforme un caractère en binaire
void transfo_Ascii(char letter, char* code_bin){
    int code  = (int)letter; // ascii code of the character
    int i = 7;
    while (i>=0){
        if (code>= pow(2,i)){
            // pow (a,b )=a^b
            code=code -pow(2,i) ;
            code_bin[7-i]= '1' ;
        }
        i -- ;
    }
    return;
}

// transforme en fichier .txt qui a des lettres en .txt binaire
void transfo_bin(char *filename){

    FILE *source = NULL;
    FILE *end = NULL;

    source = fopen(filename, "r");
    end = fopen("Output.txt", "w+");

    if (source != NULL){
        if (end != NULL){

            char letter ;
            char binary[] = "00000000" ;
            do{
                letter = fgetc(source); // récupère un caractère
                transfo_Ascii(letter, &binary) ; // le transforme en code binaire
                fputs(binary, end); // met le code binaire dans le fichier output
            }while (letter != '-' );

        }
        else
            printf("ERROR !");
    }
    else {
        printf("ERROR !");
    }

    fclose(source);
    fclose (end);
}


// compte le nb de caractères d'un fichier texte
int count_char(char *filename){

    FILE * source = NULL;
    source=fopen(filename, "r");
    if (source != NULL){
        char letter ;
        int compt = 0;
        do{
            letter = fgetc(source);
            compt++ ;
        }while (letter != EOF);
        fclose(source);
        return (compt);
    }
    else {
        printf("ERROR !");
    }
    return 0;
}
