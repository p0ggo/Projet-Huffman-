/**
 * @file write_txt.c
 * @author test
 * @brief wrinting 
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_WRITE_TXT_H
#define PJ_HUFFMAN_WRITE_TXT_H
#include "struct.h"
/**
 * @brief reset the dictionary
 * 
 */
void rst_dico();
/**
 * @brief write a text into a file 
 * 
 * @param byte 
 * @param s 
 */
void write_txt(long byte[], int s);
/**
 * @brief research an occurence in a dictionary
 * 
 * @param tmp 
 * @param val 
 * @return Node* 
 */
Node*dico_research(Node*tmp, char val);
/**
 * @brief traduce and write a text according to the huffman dictionary according to the huffman code
 * 
 * @param txt 
 * @param list 
 */
void w_huffman_code(char *txt, Letter *list);
/**
 * @brief traducing texte into ascii
 * 
 * @param avl 
 * @param txt 
 */
void w_txt_ascii(Node*avl,char*txt);

#endif //PJ_HUFFMAN_WRITE_TXT_H
