//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "random.h"

//Fct A part 2
long dec_bin(int num_dec) {
    long num_bin = 0;
    int tmp, tmp1 = 1;
    while (num_dec != 0) {
        tmp = (num_dec % 2);
        num_dec = num_dec / 2;
        num_bin = num_bin + (tmp * tmp1);
        tmp1 = tmp * 10;
    }
    return num_bin;
}

//Transform letter in byte
void let_by(char input[], long *byte, int txt_size) {
    int *ASCII = (int *) malloc(txt_size * sizeof(int));
    if (ASCII != NULL) {
        int i;
        for (i = 0; i < txt_size; i++) {
            ASCII[i] = input[i];
        }
        for (i = 0; i < txt_size; i++) {
            long tmp = dec_bin(ASCII[i]);
            byte[i] = tmp;
        }
    }
    free(ASCII);
}
