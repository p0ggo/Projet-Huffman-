//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "display_fct.h"

void display_tree(Node*node){
    if (node ==NULL){
        return NULL;
    }
    else {
        display_tree(node->left);
        display_tree(node->right);
        printf("%c a %d occurences", node->letter, node->occur);
    }
}


void display_list_occ(List_char *list) {
    List_char *tmp1 = list;
    while (tmp1 != NULL) {
        printf("%c:%d", tmp1->chara, tmp1->occur);
        tmp1 = tmp1->next;
    }
}

void chara_comparison() {
    FILE *source = fopen("../input", "r");
    int cmpt = 0;
    if (source != NULL) {
        while (fgetc(source) != EOF) {
            cmpt++;
        }
        printf("%d character on text", cmpt);
        fclose(source);
    }
    source = NULL;
    source = fopen("../output.txt", "r");
    if (source != NULL) {
        while (fgetc(source) != EOF) {
            cmpt++;
        }
        printf("%d character on text", cmpt);
        fclose(source);
    }
}
