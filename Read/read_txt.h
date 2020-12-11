/**
 * @file read_txt.h
 * @author test
 * @brief  function to read various text
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef PJ_HUFFMAN_READ_TXT_H
#define PJ_HUFFMAN_READ_TXT_H
#include "struct.h"
/**
 * @brief 
 * 
 * @param exit 
 */
void read_txt(char *exit);
/**
 * @brief 
 * 
 * @param txt 
 * @param listChar 
 * @return Letter* 
 */
Letter * r_s_dico (char*txt, List_char*listChar);

#endif //PJ_HUFFMAN_READ_TXT_H
