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

