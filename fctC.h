typedef struct Element{
    char character;
    int occ;
    struct Element *next;
}Element;
/**
 * @brief function that looks if a character is already in the list, return 1 if the element is in the list and 0 otherwise
 * 
 * @param letter 
 * @param liste 
 * @return Element* 
 */
Element* search_char(char letter, Element* liste);
/**
 * @brief function that returns a list of each and every character in the text, and the number of occurence of those characters
 * 
 * @param filename 
 * @return Element* 
 */
Element* create_list_from_txt(char *filename);
