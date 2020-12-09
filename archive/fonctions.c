#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

//function that looks if a character is already in the list, return 1 if the element is in the list and 0 otherwise
int search_char(char letter, Element* list){
    while (list != NULL)
    {
        if(list -> character == letter){
            return 1;
        }
        list = list -> next;
    }
    return 0;
}

// function that returns a list of each and every character in the text, and the number of occurence of those characters
Element* partC(char *filename){

    FILE * source = NULL;
    source=fopen(filename, "r");
    if (source != NULL){
        char letter ;
        Element* newElement;
        newElement = (Element*)malloc(sizeof (Element));
        newElement -> character = EOF;
        newElement -> occ = 0;
        newElement -> next = NULL;
        do{
            letter = fgetc(source);
            int res = search_char(letter, newElement);
            if(res==0){
                Element* newElement2;
                newElement2 = (Element*)malloc(sizeof (Element));
                newElement2 -> character = letter;
                newElement2 -> occ = 1;
                newElement2 -> next = NULL;
                newElement -> next = newElement2;
                newElement = newElement -> next;
            }
            else
            {
                while (newElement != NULL){
                    if((newElement -> character) == letter){
                        (newElement -> occ)++ ;
                    }
                    newElement = newElement -> next;
                }
            }

        }while (letter != EOF);
        fclose(source);
        return (newElement);
    }
    else {
        printf("ERROR !");
        return (NULL) ;
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
    printf("Trouv�\n");
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

void dico(Node* tree, Node* letter){
    FILE* fichier = fopen("dico.txt", "w+");
    if(tree != NULL){
            if(letter != letter->next){
                recherche_en_profondeur(tree->next, letter, chemin);
                fprintf(fichier,"%c : %d", letter, chemin);
        }
    }

    fclose(fichier);
}



//
// Created by Chloé  Rolland  on 27/11/2020.
//

/*——————-Création de l’arbre——————–*/
struct arbre_huff * creer_arbre(unsigned int arbreN[])
{
    unsigned int i;
    struct temp_huff tmp;
    struct arbre_huff *arbre;
    unsigned int cpt_max=0;

    /* Initialisation */
    tmp.restant=0;

    for (i=0;i<MAX;i++)
    {
        /* On enlève les caractères qui ne sont pas dans le fichier */
        if (!arbreN[i])
            continue;

        /* Insertion dans l’arbre de chaque caractère */
        if(!(arbre=malloc(sizeof(*arbre))))
        {
            perror("Erreur dans malloc de la fonction creer_arbre ");
            exit(EXIT_FAILURE);
        }
        /* Remplissage des feuilles */
        arbre->c=(char)i;
        arbre->gauche=NULL;
        arbre->droite=NULL;
        arbre->occurence=arbreN[i];
        if((arbre->occurence)>cpt_max) /* On garde en mémoire le nombre d’occurence max */
            cpt_max=arbre->occurence;
        ajouter_temp_huff(&tmp,arbre);
    }

    while(tmp.restant>1) /* Tant que l’on a pas la racine de l’arbre */
    {
        if (!(arbre=malloc(sizeof(*arbre))))
        {
            perror("Erreur dans malloc() de la fonction creer_arbre ");
            exit(EXIT_FAILURE);
        }
        arbre->gauche=nouveau_noeud(&tmp);
        arbre->droite=nouveau_noeud(&tmp) ;
        arbre->occurence=arbre->gauche->occurence + arbre->droite->occurence; /* Le nouveau noeud crée à pour poids la somme des deux précédents */

        ajouter_temp_huff(&tmp,arbre);
    }

    /* On possède maintenant juste la racine de l’arbre */
    arbre=nouveau_noeud(&tmp);
    return arbre;
}
/*———————Ajouter_temp_huf——————————*/
void ajouter_temp_huff(struct temp_huff *tmp, struct arbre_huff *arbre)
{
    int i;

    /* Recherche de la position ou inserer */
    for(i=tmp->restant;(tmp->restant>0) && ((tmp->noeud[i-1]->occurence)<(arbre->occurence));)
    {
        tmp->noeud[i]=tmp->noeud[i-1];
        if(!(–i))
        break;
    }
    /* Insertion des noeuds de l’arbre */
    tmp->noeud[i]=arbre;
    tmp->restant++;
}

/*————–Recuparation de la valeur ayant la plus faible occurence——–*/
struct arbre_huff * nouveau_noeud(struct temp_huff *tmp)
{
    /* On teste que le fichier n’est pas vide */
    if(tmp->restant==0)
    {
        perror("Le fichier ne contient aucune donnée ");
        exit(EXIT_FAILURE);
    }
    (tmp->restant)–;
    return tmp->noeud[tmp->restant];
}

/*———————-Suppression de l’arbre de Huffman———————*/
/*—– Algorithme de suppression de l’arbre binaire de Huffman —–*/
/* Cette fonction récursive va supprimer un arbre binaire en parcourant */
/* tous les fils et en remontant jusqu'à la racine.                     */
void suppr_arbre(struct arbre_huff **arbre)
{
    if((*arbre)->gauche && (*arbre)->droite)
    {
        suppr_arbre(&(*arbre)->gauche);
        suppr_arbre(&(*arbre)->droite);
        free(*arbre);
        *arbre=NULL;
    }
}




