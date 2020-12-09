//
// Created by Chloé  Rolland  on 07/12/2020.
//

#ifndef PJ_HUFFMAN_STRUCT_H
#define PJ_HUFFMAN_STRUCT_H

typedef struct List_char {
    char chara;
    struct List_char *next;
    int occur;
} List_char;

typedef struct Node {
    char chara;
    int occur;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct Queue {
    int side;
    int back;
    int size;
    struct Node **node_array;
} Queue;

typedef struct Letter {
    char letter[5];
    char code[10];
    struct Letter *next;
} Letter;

typedef struct Tree {
    int array_node;
    int size;
}Tree;

typedef struct Dictionary {
    Letter *chara;
    int s;
} Dictionary;

#endif //PJ_HUFFMAN_STRUCT_H
