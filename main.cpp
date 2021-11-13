#include "tree/tree.h"

//===================================================================

int main(int, char* argv[]) {

    FILE* logs_file = open_log_file(argv[1]);
    if (logs_file == NULL)
        return -1;

    struct Tree tree = { 0 };

    int err_val = tree_ctor(&tree); $

    node_init(tree.root, "root");

    node_add_sons(tree.root);

    node_init(tree.root->left_son, "left");
    node_init(tree.root->right_son, "right");

    Node* right = tree.root->right_son;
    Node* left = tree.root->left_son;

    node_add_sons(left);

    node_init(left->right_son, "leftright");
    node_init(left->left_son, "leftleft");

    node_add_right_son(right);
    node_init(right->right_son, "rightright");

    tree_draw_graph(&tree);

    tree_delete_branch(&tree.root->left_son);

    fprintf(logs_file, "<pre> \n tree.root->left_son is %p \n </pre>", tree.root->left_son);

    tree_dtor(&tree);


    close_log_file(); $

    return 0;
}