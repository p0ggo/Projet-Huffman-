#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Read/read_txt.h"
#include "Writing/write_txt.h"
#include "struct.h"
#include "Random/random.h"
#include "Arbre/tree.h"
#include "Affichage/display_fct.h "
#include "Liste/list.h"


#include <math.h>
#include "fonctions.h"
#include "fctC.h"

#define CHARMAX 1000

int main (){
  
    transfo_bin("input.txt");

    int a ;
    a = count_char("input.txt");
    printf("%d\n", a) ;
  
    // test fct C 
    Element* maliste = NULL ;
    maliste= create_list_from_txt("input.txt");
    afficherListe (maliste);
    free(maliste);



} 
