//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "node.h"

void tree_free(Node*f_node){
    if(f_node !=NULL){
        tree_free(f_node->left);
        tree_free(f_node->right);
        free(f_node);
    }
}

Node *create_node(char info, int occur) {

    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp != NULL) {
        tmp->right = NULL;
        tmp->left = NULL;
        tmp->chara = info;
        tmp->occur = occur;
    }
    return tmp;
}

void swap_node(Node**n1,Node**n2){
    Node*tmp=*n1;
    *n1=*n2;
    *n2=tmp;
}
