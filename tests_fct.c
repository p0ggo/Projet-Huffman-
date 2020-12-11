#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "part1_fonctions.h"
#include "part2_fonctions.h"
#include "part3_fonctions.h"

void afficherListe (Element * liste){

    Element * temp ;
    temp = liste ;
    while (temp != NULL){
        printf("%c, ", temp->character);
        printf("%d \n", temp->occ) ;
        temp = temp->next ;
    }
}

void test_fct(){
  // test fct A
  transfo_bin("input.txt") ;
  //ouvrir le fichier ouput pour vérifier qu'il y a bien des 0 et des 1 dedans 
  
  //test fct B
  int a ;
  a = count_char("input.txt");
  printf("%d\n", a) ;

  // test fct C 
  Element* maliste = NULL ;
  maliste= create_list_from_txt("input.txt");
  afficherListe (maliste);
  free(maliste);
    
  // test fct D 
   if (node ==NULL){
      return NULL;
    }
    else {
        display_tree(node->left);
        display_tree(node->right);
        printf("%c a %d occurences", node->chara, node->occur);
    }
    
    // test fct E
  
  
  
  
}



