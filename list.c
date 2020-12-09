//
// Created by Chloé  Rolland  on 07/12/2020.
//

#include "list.h"

int already_list(List_char *L, char chara) {
    int i = 1;
    List_char *tmp1;
    tmp1 = L;
    while (tmp1 != NULL) {
        if (tmp1->chara == chara) {
            return i;
        }
        tmp1 = tmp1->next;
        i++;
    }
    return -1;
}

List_char *count_occ(char string[CHARMAX]) { //length max == CHARMAX define on top
    int i;
    List_char *list = (List_char *) malloc(sizeof(List_char));
    List_char *tmp1 = list, *tmp2;

    for (i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            string[i] = '*'; // space equivalent
        }
    }
    for (i = 0; i < strlen(string); i++) {
        if (string[i] == 10) { // 10 = ASCII code line feed
            string[i] = '-'; // line feed equivalent
        }
    }

    if (list != NULL) {
        if (strlen(string) > 0) { // waist list of Upper 0
            list->next = NULL;// first list value
            list->chara = string[0];
            list->occur = 1;

            for (i = 1; i < strlen(string); i++) {
                int position = already_list(list, string[i]);
                if (position == -1) {
                    List_char *new_let = (List_char *) malloc(sizeof(List_char));
                    if (new_let != NULL) {
                        new_let->chara = string[i];
                        new_let->occur = 1;
                        new_let->next = NULL;
                        tmp1->next = new_let;
                        tmp1 = tmp1->next;
                    }
                } else {
                    int cmpt = 1;
                    tmp2 = list;
                    while (cmpt != position && tmp2 != NULL) {
                        tmp2 = tmp2->next;
                        cmpt += 1;
                    }
                    tmp2->occur += 1;
                }
            }
            return list;
        }
    }
    return NULL;
}

int size_list_char(List_char *l) {
    int s = 0;
    List_char *tmp = l;
    if (tmp != NULL) {
        while (tmp->next != NULL) {
            s++;
            tmp = tmp->next;
        }
        return s;
    }
    return s;
}

List_char *listofchar(List_char *list_a) {
    if (list_a->next == NULL) { // only elements
        return list_a;
    } else if (list_a == NULL)// empty
        return NULL;
    else {
        /* TODO: check if necessary
         * do {
         */
        List_char *f_node = list_a; //f_node = first node = root
        int start;
        // begin
        List_char *anterior = NULL;
        List_char *element = f_node;
        List_char *achieve = element->next;
        start = 0;
        while (achieve != NULL) {
            if (achieve->occur < element->occur) {
                start = 1;
                // new browse of list if bad order in list

                // element inversion
                if (anterior == NULL) {
                    f_node = achieve;
                } else {
                    anterior->next = achieve;
                }
                element->next = achieve->next;
                achieve->next = element;
                anterior = achieve;
                achieve = element->next;
            } else {
                // if everything is good --> continue
                anterior = element;
                element = element->next;
                achieve = element->next;
            }

        }
        return f_node;
        /* TODO: probably a mistake
         * } while (
         * element->next != EOF);*/
    }
}

