//
// Created by Chloé  Rolland  on 07/12/2020.
//

#ifndef PJ_HUFFMAN_TREE_H
#define PJ_HUFFMAN_TREE_H
#include "struct.h
#include "node.h"

int leaf(Node *f_node);
void tree_leaf_path(Node*f_node, int array[], int top);
Node*AVL_creation(char list_char_char[256], char*list_char_code[256], int start,int end);
void Dico_creation(int array[], int n, Node*f_node);
int size_waiting_list(Tree *tree);
void min_h(Tree*tree,int index);
Node*min_node(Tree*tree);
void node_in_tree(Tree*tree, Node*node);
void tree_building(Tree*tree);
Tree*tree_creation(char arr_char[], int arr_occur[],int s);
Tree*huffman_tree(char arr_char[], int arr_occur[],int s);
Tree *huffman_code(char arr_char[], int arr_occur[], int s);

#endif //PJ_HUFFMAN_TREE_H
