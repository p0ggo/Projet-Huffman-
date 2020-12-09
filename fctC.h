typedef struct Element{
    char character;
    int occ;
    struct Element *next;
}Element;

Element* search_char(char letter, Element* liste);

Element* create_list_from_txt(char *filename);
