//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "write_txt.h"
#define CHARMAX 1000


void rst_dico() { //reset dico
    FILE *source = fopen(".../dico.txt", "r");
    fclose(source);
}

//write on new file
void write_txt(long byte[], int s) {
    FILE *source = fopen("../output.txt", "w");
    int i;
    if (source != NULL) {
        for (i = 0; i < s; i++) {
            fprintf(source, "%ld", byte[i]);

        }
        fclose(source);
    }
}

Node*dico_research(Node*tmp, char val){
    if (tmp ==NULL || tmp->letter==val){
        return tmp;
    }
    if(tmp->letter<val){
        return dico_research(tmp->right,val);
    }
    return(tmp->left,val);
}

void w_huffman_code(char *txt, Letter *list) {
    FILE *source;
    source = fopen(".../Huffman.txt", "w");
    if (source != NULL) {
        int s, i;
        s = (int) strlen(txt);
        Node*node;
        Letter *tmp = list;
        for (i = 0; i < s; i++) {
            node=dico_research(avl,txt[i]);
            if (node !=NULL) {
                fprintf(source, "%s", node->huffman_code);
            }
        }
        fuptc(42,source);
        fclose(source);
    }
}

void w_txt_ascii(Node*avl,char*txt){
    FILE*source = fopen("../decompressed.txt","w");
    if(source==NULL){
        printf("error");
    }
    else {
        char tmp1;
        int i=0,y=0;
        char array[30];
        for (i=0; i <strlen(txt);i++){
            while (txt[i] != 42){
                if (txt[i]==32){
                    for (y=0;y<=24,y++){
                        array[y]='2';
                    }
                    i++
                }
                else {
                   array[i]=txt[i];
                   i++;
                }
            }
            printf("%s", array);
        }
        fclose(source);
    }
}

