/**
 * @file list.h
 * @author test
 * @brief function related to the list
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_LIST_H
#define PJ_HUFFMAN_LIST_H
#include "struct.h"
/**
 * @brief check if a character is already in the list 
 * 
 * @param L 
 * @param chara 
 * @return int 
 */
int already_list(List_char *L, char chara);
/**
 * @brief count the number of occurence in a text for each and every character 
 * 
 * @param string 
 * @return List_char* 
 */
List_char *count_occ(char string[CHARMAX]);
/**
 * @brief create a list 
 * 
 * @param list_a 
 * @return List_char* 
 */
List_char *listofchar(List_char *list_a);
/**
 * @brief give the size of the list 
 * 
 * @param l 
 * @return int 
 */
int size_list_char(List_char *l);
#endif //PJ_HUFFMAN_LIST_H
