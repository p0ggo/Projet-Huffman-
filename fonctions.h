typedef struct Element{
    char character;
    int occ;
    struct Element *next;
}Element;

int search_char(char letter, Element* list);

Element* partC(char *filename);
