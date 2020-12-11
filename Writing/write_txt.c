

#include "write_txt.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARMAX 1000


void rst_dico() { //reset dico
    FILE *source = fopen(".../dico.txt", "r");
    fclose(source);
}

//write on new file
void write_txt(long byte[], int s) {
    FILE *source = fopen("../output.txt", "w");
    int i;
    if (source != NULL) {
        for (i = 0; i < s; i++) {
            fprintf(source, "%ld", byte[i]);

        }
        fclose(source);
    }
}

Node*dico_research(Node*tmp, char val){
    if (tmp ==NULL || tmp->letter==val){
        return tmp;
    }
    if(tmp->letter<val){
        return dico_research(tmp->right,val);
    }
    return(tmp->left,val);
}

void w_huffman_code(char *txt, Letter *list) {
    FILE *source;
    source = fopen(".../Huffman.txt", "w");
    if (source != NULL) {
        int s, i;
        s = (int) strlen(txt);
        Node*node;
        Letter *tmp = list;
        for (i = 0; i < s; i++) {
            node=dico_research(avl,txt[i]);
            if (node !=NULL) {
                fprintf(source, "%s", node->huffman_code);
            }
        }
        fuptc(42,source);
        fclose(source);
    }
}

void w_txt_ascii(Node*avl,char*txt){
    FILE*source = fopen("../decompressed.txt","w");
    if(source==NULL){
        printf("error");
    }
    else {
        char tmp1;
        int i=0,y=0;
        char array[30];
        for (i=0; i <strlen(txt);i++){
            while (txt[i] != 42){
                if (txt[i]==32){
                    for (y=0;y<=24,y++){
                        array[y]='2';
                    }
                    i++
                }
                else {
                   array[i]=txt[i];
                   i++;
                }
            }
            printf("%s", array);
        }
        fclose(source);
    }
}

int recherche_en_profondeur(Node *tree, char letter, char *chemin)
{
  if (tree->info != letter)
  {
    if (tree->left != NULL)
    {
      chemin = realloc(chemin, sizeof(strlen(chemin) + 1));
      chemin = ajouter_lettre(chemin, "0");
      return recherche_en_profondeur(tree->left, letter, chemin);
    }

    if (tree->right != NULL)
    {
      chemin = realloc(chemin, sizeof(strlen(chemin) + 1));
      chemin = ajouter_lettre(chemin, "1");
      return recherche_en_profondeur(tree->right, letter, chemin);
    }

    chemin[strlen(chemin) - 1] = '\0';
  }
  else if (tree->info == letter)
  {
    printf("Trouve\n");
    return 1;
  }
  else
  {
    printf("Pas dans l'arbre.\n");
    return -1;
  }
}

char *ajouter_lettre(char *tableau_initial, char lettre_a_rajouter)
{
  return strcat(tableau_initial, lettre_a_rajouter);
}

// write in the dico, the char of a node
void Dico_creation(int array[], int n, Node*f_node) {
    int i;
    FILE *source = fopen("dico.txt", "a");
    if (source != NULL) {
        fputc(f_node->chara,source);
        fputc(32,source);
        for (i = 0; i < n; i++) {
            fputc(array[i]+48,source);
        }
        fputc(0,source);
        fputc(10,source);
        fclose(source);
    }
}


//verify if a node is a leaf
int leaf(Node *f_node) {
    if (f_node->right != NULL && f_node->left != NULL) {
        return 1;
    } else {
        return 0;
    }
}


void write_dico_w_Huffmantree (Node* tree){
    if (tree != NULL){
        if (leaf(tree)==0){
            char * code_bin ="";
            int res = recherche_en_profondeur(tree, tree->chara, code_bin ) ;
            if (res != -1){
                int n = strlen(chemin) ; // size of the binary code
                Dico_creation(code_bin , n, tree) ;
            }
        }
        write_dico_w_Huffmantree(tree->left);
        write_dico_w_Huffmantree(tree->right);
    }
}

void write_dico (Node* tree){
    rst_dico();
    write_dico_w_Huffmantree (Node* tree);
}

