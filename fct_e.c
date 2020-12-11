

typedef struct Node {
    char character;
    int occ;
    struct Node* gauche ;
    struct Node* droite ;
}Node;

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

//reset dico
void rst_dico() {
    FILE *source = fopen("dico.txt", "w+");
    fclose(source);
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
            int res = recherche_en_profondeur(tree, tree->character, code_bin ) ;
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
