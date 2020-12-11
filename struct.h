/**
 * @file struct.h
 * @author test
 * @brief  various structure useful to every function 
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_STRUCT_H
#define PJ_HUFFMAN_STRUCT_H
/**
 * @brief List of char structur
 * 
 */
typedef struct List_char {
    char chara;
    struct List_char *next;
    int occur;
} List_char;
/**
 * @brief Node structur
 * 
 */
typedef struct Node {
    char chara;
    int occur;
    struct Node *right;
    struct Node *left;
} Node;
/**
 * @brief 
 * 
 */
typedef struct Queue {
    int side;
    int back;
    int size;
    struct Node **node_array;
} Queue;
/**
 * @brief Letter structur 
 * 
 */
typedef struct Letter {
    char letter[5];
    char code[10];
    struct Letter *next;
} Letter;
/**
 * @brief tree sctructur
 * 
 */
typedef struct Tree {
    int array_node;
    int size;
}Tree;
/**
 * @brief dictionary structur
 * 
 */
typedef struct Dictionary {
    Letter *chara;
    int s;
} Dictionary;

#endif //PJ_HUFFMAN_STRUCT_H
