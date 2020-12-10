//
// Created by Chloé  Rolland  on 07/12/2020.
//

#ifndef PJ_HUFFMAN_WRITE_TXT_H
#define PJ_HUFFMAN_WRITE_TXT_H
#include "struct.h"

void rst_dico();
void write_txt(long byte[], int s);
Node*dico_research(Node*tmp, char val);
void w_huffman_code(char *txt, Letter *list);
void w_txt_ascii(Node*avl,char*txt);

#endif //PJ_HUFFMAN_WRITE_TXT_H
