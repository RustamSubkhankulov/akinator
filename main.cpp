#include "akinator/akinator.h"

//===================================================================

int main(int, char* argv[]) {

    FILE* logs_file = open_log_file(argv[1]);
    if (logs_file == NULL)
        return -1;

    struct Tree tree = { 0 };

    int err_val = tree_ctor(&tree); $

    akinator_init_base(&tree, "tree_text/tree_input.txt");
    tree_save_to_file(&tree, "temp.txt");
    tree_dtor(&tree);

    tree_ctor(&tree);
    akinator_init_base(&tree, "temp.txt");
    tree_save_to_file(&tree, "temp2.txt");

    close_log_file(); $

    return 0;
}