#include "akinator/akinator.h"
#include "text_processing/text_processing.h"

#include "general/general.h"

//===================================================================

int main(int, char* argv[]) {

    FILE* logs_file = open_log_file(argv[1]);
    if (logs_file == NULL)
        return -1;

    struct Tree tree = { 0 };
    struct Text text = { 0 };

    int err_val = akinator_tree_ctor(&tree); $
    akinator_init_base(&tree, &text, argv[2]);

    akinator_play_game(&tree);

    tree_dtor(&tree);
    akinator_free_allocated_mem();
    text_clear_mem(&text, text.buf);

    close_log_file(); $

    return 0;
}