#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"

//function that looks if a character is already in the list, return 1 if the element is in the list and 0 otherwise
Element* search_char(char letter, Element* liste){
    while (liste != NULL)
    {
        if(liste -> character == letter){
            return liste;
        }
        liste = liste -> next;
    }
    return NULL;
}


// function that returns a list of each and every character in the text, and the number of occurence of those characters
Element* create_list_from_txt(char *filename){

    FILE * source = NULL;
    source=fopen(filename, "r");
    if (source != NULL){
        char letter ;
        Element* firstElement = NULL;
        Element* lastElement = NULL;

        do{
            letter = fgetc(source);
            Element* res = search_char(letter, firstElement);

            // we create a new Element because, he is not in the list
            if(res != NULL){
                ++(res->occ);
            } else {
                Element* newElement;
                newElement = (Element*)malloc(sizeof (Element));
                newElement -> character = letter;
                newElement -> occ = 1;
                newElement -> next = NULL;
                if (firstElement == NULL) { // first element to add to the list
                    firstElement = lastElement = newElement;
                } else {
                    lastElement->next = newElement;
                    lastElement = newElement;
                }
            }

        }while (letter != EOF);
        fclose(source);
        return (firstElement);
    }
    else {
        printf("ERROR !");
        return (NULL) ;
    }
}

void afficherListe (Element * liste){
    Element * temp ;
    temp = liste ;
    while (temp != NULL){
        printf("%c, ", temp->character);
        printf("%d \n", temp->occ) ;
        temp = temp->next ;
    }
}

