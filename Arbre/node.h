/**
 * @file node.h
 * @author test
 * @brief function concerning the creation of nodes
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_NODE_H
#define PJ_HUFFMAN_NODE_H
#include "struct.h"
/**
 * @brief free the memory allocation of the tree
 * 
 * @param f_node 
 */
void tree_free(Node*f_node);
/**
 * @brief Create a node object
 * 
 * @param info 
 * @param occur 
 * @return Node* 
 */
Node *create_node(char info, int occur);
/**
 * @brief switch the right and left 
 * 
 * @param n1 
 * @param n2 
 */
void swap_node(Node**n1,Node**n2);

#endif //PJ_HUFFMAN_NODE_H
