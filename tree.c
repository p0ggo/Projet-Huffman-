//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "tree.h"
#include "struct.h"

int leaf(Node *f_node) {
    if (f_node->right != NULL && f_node->left != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void tree_leaf_path(Node*f_node, int array[], int top){
    if (f_node->left){
        arr[top]=0;
        tree_leaf_path(f_node->left,array,top+1);
    }
    if(f_node->right){
        array[top]=1;
        tree_leaf_path(f_node->right,array,top+1);
    }
    if (leaf(f_node)){
        dico_creation(array,top,f_node);
    }
}

Node*AVL_creation(char list_char_char[256], char*list_char_code[256], int start,int end){
    if (start > end){
        return NULL;
    }
    int middle ;
    middle = (start+end);
    Node*f_node= (Node*)malloc(sizeof(Node));
    f_node->letter=list_char_char[middle];
    // copie bloc memoire source vers destination
    memmove(f_node-> huffman_code, list_char_code[middle], sizeof(char*)256);
    f_node->right=AVL_creation(list_char_char,list_char_code,middle+1,end);
    f_node->left=AVL_creation(list_char_char,list_char_code,start,mid-1,end);
    return f_node;
}

void Dico_creation(int array[], int n, Node*f_node) {
    int i;
    FILE *source = fopen("../dico.txt", "a");
    if (source != NULL) {
        fputc(f_node->letter,source);
        fputc(32,source);
        for (i = 0; i < n; i++) {
            fputc(array[i]+48,source);
        }
        fputc(0,source);
        fputc(10,source);
        fclose(source);
    }
}

int size_waiting_list(Tree *tree) {
    if (tree->side == 1) {
        return 1;
    } else {
        return 0;
    }
}

void min_h(Tree*tree,int index){
    int small =index;
    int left = 2*index+1;
    int right=2*index+2;
    if ((right<tree->size) && tree-> array_node[right]->occur < tree-<arrayf_node[smallest]->occur){
        small=right;
    }
    if ((left<tree->size) && tree-> array_node[left]->occur<tree-<arrayf_node[smallest]->occur){
        small=left;
    }
    if (small!=index){
        swap_node(&tree->array_node[small],&&tree->array_node[index]);
        min_h(tree,small);
    }
}

Node*min_node(Tree*tree){
    Node*tmp= tree->array_node[0];
    tree->array_node[0]=tree->array_node[tree->size-1];
    min_h(tree,0);
    return tmp;
}

void node_in_tree(Tree*tree, Node*node){
    tree->size++;
    int i,
    i = tree->size-1;
    while (i&& node->occur<tree->array_node[(i-1)/2]->occur){
        tree->array_node[i]= tree->array_node[(i-1)/2];

    }
    tree->array_node[i]=node;
}

void tree_building(Tree*tree){
    int n;
    int i;
    n=tree->size-1;
    for (i=(n-1)/2;i>=0;i--){
        min_h(tree,i);
    }
}

Tree*tree_creation(char arr_char[], int arr_occur[],int s){
    Tree*tree=tree_creation(s);
    for (int i = 0;i<s; ++i){
        tree->array_node[i]=create_node (arr_char[i],arr_occur[i]);
    }
    tree->size=s;
    tree_building(tree);
    return tree;
}

Tree*huffman_tree(char arr_char[], int arr_occur[],int s){
    Node*left;
    Node*right;
    Node*top;
    Tree*tree=tree_creation(arr_char,arr_occur,s);
    while(!size_waiting_list(tree)){
        right= min_node(tree);
        left = min_node(tree);
        top=create_node ('*', right->occur+left->occur);
        top->right=right;
        top->left=left;
        node_in_tree(tree,top);
    }
    return min_node(tree);
}

Tree *huffman_code(char arr_char[], int arr_occur[], int s) {
    Tree *f_node = huffman_tree(arr_char,arr_occur,s);
    int arr[CHARMAX];
    int top = 0;
    tree_leaf_path(f_node,arr,top);
    return f_node;
}

