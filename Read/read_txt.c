//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "read_txt.h"
#define CHARMAX 1000


// Function A part 1
void read_txt(char *exit) {
    FILE *source = NULL;
    char str[CHARMAX];
    source = fopen(".../input.txt", "r");
    if (source == NULL) {
        printf("error from file");
    } else if (source != NULL) {
        char tmp=fgetc(source);
        while (tmp!= EOF&& i<CHARMAX) {
            if(tmp == 10){
                tmp=37;
            }
            else if(tmp<0|tmp>127) {
                tmp=63;
            }
            else {
                exit[i]=tmp;
                tmp=fgetc(source);
                i++;
            }
        }
        if (tmp !=EOF) {
            printf("error");
        }
        fclose(source);
        }

    }

Letter * r_s_dico (char*txt, List_char*listChar){
    FILE*source= fopen("dico.txt","r");
    char str[CHARMAX];
    if(source==NULL){
        printf('error');
    }
    else{
        Letter*f_node=(Letter*)malloc(sizeof(Letter));
        Letter*tmp=f_node;
        if(tmp!=NULL){
            char tmp1=fgetc(source);
            while (tmp1 !=EOF){
                tmp->letter=tmp1;
                fgetc(source);
                tmp1=fgetc(source);
                signed int cmpt=0;
                while (tmp !=10){
                    tmp->code[cmpt]=tmp1;
                    cmpt++;
                    tmp1=fgetc(source);
                }
                tmp1=fgetc(source);
                tmp->next=(Letter*)malloc(sizeof(Letter));
                tmp=tmp->next;
            }
            tmp->next=NULL;
        }
        //ajouter suppression du dernier noeud
        fclose(source);
        return f_node;
    }
}

//Need fct txt compressed
