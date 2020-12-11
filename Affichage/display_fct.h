/**
 * @file display_fct.h
 * @author test
 * @brief display of the various things 
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_DISPLAY_FCT_H
#define PJ_HUFFMAN_DISPLAY_FCT_H
#include "struct.h"
#include "list.h
#include"node.h"

/**
 * @brief displaying the huffman tree
 * 
 * @param node 
 */
void display_tree(Node*node);
/**
 * @brief displaying the list of occurence
 * 
 * @param list 
 */
void display_list_occ(List_char *list);
/**
 * @brief displaying the number of character in a text
 * 
 */
void chara_comparison();

#endif //PJ_HUFFMAN_DISPLAY_FCT_H
