void compress_txt(){
    Element* Lsc = create_list_from_txt("input.txt");
    Node* huffmantree = huffman_tree(Lsc);
    write_dico(huffmantree);
    w_huffman_code ();
}
