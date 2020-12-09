//
// Created by Chloé  Rolland  on 07/12/2020.
//

#ifndef PJ_HUFFMAN_NODE_H
#define PJ_HUFFMAN_NODE_H
#include "struct.h"

void tree_free(Node*f_node);
Node *create_node(char info, int occur);
void swap_node(Node**n1,Node**n2);

#endif //PJ_HUFFMAN_NODE_H
