#include <stdlib.h>
#include <stdio.h>

// partie A

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;

    fichier = fopen("input.txt", "r");

    fclose(fichier);

    return 0;
}
