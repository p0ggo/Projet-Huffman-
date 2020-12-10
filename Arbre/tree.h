/**
 * @file tree.h
 * @author test
 * @brief fonction concerning the huffman tree 
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PJ_HUFFMAN_TREE_H
#define PJ_HUFFMAN_TREE_H
#include "struct.h
#include "node.h"
/**
 * @brief creation of the different leaf 
 * 
 * @param f_node 
 * @return int 
 */
int leaf(Node *f_node);
/**
 * @brief create the path to parcour the tree from the bottom to the top
 * 
 * @param f_node 
 * @param array 
 * @param top 
 */
void tree_leaf_path(Node*f_node, int array[], int top);
/**
 * @brief function of la partie 3 (L)
 * 
 * @param list_char_char 
 * @param list_char_code 
 * @param start 
 * @param end 
 * @return Node* 
 */
Node*AVL_creation(char list_char_char[256], char*list_char_code[256], int start,int end);
/**
 * @brief creation of the dictionary
 * 
 * @param array 
 * @param n 
 * @param f_node 
 */
void Dico_creation(int array[], int n, Node*f_node);
/**
 * @brief creation of a FIFO
 * 
 * @param tree 
 * @return int 
 */
int size_waiting_list(Tree *tree);
/**
 * @brief Determine the minimum in the dictionary 
 * 
 * @param tree 
 * @param index 
 */
void min_h(Tree*tree,int index);
/**
 * @brief determine the minimum to put in the nodes 
 * 
 * @param tree 
 * @return Node* 
 */
Node*min_node(Tree*tree);
/**
 * @brief Putting the nodes in the right place 
 * 
 * @param tree 
 * @param node 
 */
void node_in_tree(Tree*tree, Node*node);
/**
 * @brief Construction of the tree and various nodes 
 * 
 * @param tree 
 */
void tree_building(Tree*tree);
/**
 * @brief assembling what comes out of the tree_building
 * 
 * @param arr_char 
 * @param arr_occur 
 * @param s 
 * @return Tree* 
 */
Tree*tree_creation(char arr_char[], int arr_occur[],int s);
/**
 * @brief Switching the tree upside down
 * 
 * @param arr_char 
 * @param arr_occur 
 * @param s 
 * @return Tree* 
 */
Tree*huffman_tree(char arr_char[], int arr_occur[],int s);
/**
 * @brief Create the huffman dictionary according to the tree 
 * 
 * @param arr_char 
 * @param arr_occur 
 * @param s 
 * @return Tree* 
 */
Tree *huffman_code(char arr_char[], int arr_occur[], int s);

#endif //PJ_HUFFMAN_TREE_H
