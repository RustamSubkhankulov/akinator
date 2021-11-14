#include "akinator/akinator.h"
#include "text_processing/text_processing.h"

//===================================================================

int main(int, char* argv[]) {

    FILE* logs_file = open_log_file(argv[1]);
    if (logs_file == NULL)
        return -1;

    struct Tree tree = { 0 };
    struct Text text = { 0 };

    int err_val = tree_ctor(&tree); $
    akinator_init_base(&tree, &text, "tree_text/tree_input.txt");
    tree_save_to_file(&tree, "temp.txt");
    tree_dtor(&tree);

    text_clear_mem(&text, text.buf);

    struct Text text2 = { 0 };

    tree_ctor(&tree);
    akinator_init_base(&tree, &text2, "temp.txt");
    tree_save_to_file(&tree, "temp2.txt");
    tree_dtor(&tree);

    text_clear_mem(&text2, text2.buf);

    close_log_file(); $

    return 0;
}