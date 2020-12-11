#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "read_txt.h"
#include "write_txt.h"
#include "struct.h"
#include "random.h"
#include "tree.h"

#include <math.h>
#include "fonctions.h"

#define CHARMAX 1000

int main (){
  
    transfo_bin("input.txt");

    int a ;
    a = count_char("input.txt");
    printf("%d\n", a) ;



} 
