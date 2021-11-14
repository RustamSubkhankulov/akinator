#pragma once

#include "akinator_config.h"
#include "../tree/tree.h"

//===================================================================

#ifdef AKINATOR_LOGS

    #define akinator_log_report() \
            log_report()

#else

    #define akinator_log_report() ""

#endif

#ifdef AKINATOR_TREE_VERIFICATE

    #define AKINATOR_TREE_VERIFICATION(tree) {                      \
                                                                    \
        do                                                          \
        {                                                           \
            int is_ok = akinator_tree_validator(tree);              \
            if (is_ok == -1)                                        \
                return -1;                                          \
        } while(0);                                                 \
    }                                           

#else 

    #define AKINATOR_TREE_VERIFICATION(tree) ""

#endif

//===================================================================

#define BUFFER_STRUCT_PTR_CHECK(buffer_struct_ptr) {                \
                                                                    \
    if (buffer_struct_ptr == NULL) {                                \
                                                                    \
        error_report(BUFFER_STRUCT_INV_PTR);                        \
        return -1;                                                  \
    }                                                               \
}

//===================================================================

#define buffer_struct_init(buffer_struct, buffer, size, pos) \
       _buffer_struct_init(buffer_struct, buffer, size, pos, LOG_ARGS)

#define buffer_dump(buffer_struct) \
       _buffer_dump(buffer_struct, LOG_ARGS)

#define tree_read_from_file(tree, text, filename) \
       _tree_read_from_file(tree, text, filename, LOG_ARGS)

#define node_read_from_buffer(node, buffer_struct) \
       _node_read_from_buffer(node, buffer_struct, LOG_ARGS)

#define akinator_init_base(tree, text, filename) \
       _akinator_init_base(tree, text, filename, LOG_ARGS)

#define akinator_tree_ctor(tree) \
       _akinator_tree_ctor(tree, LOG_ARGS)

#define akinator_tree_validator(tree) \
       _akinator_tree_validator(tree, LOG_ARGS)

#define akinator_node_validator(node) \
       _akinator_node_validator(node, LOG_ARGS)

#define akinator_tree_search(tree, stack, hash) \
       _akinator_tree_search(tree, stack, hash, LOG_ARGS)

#define akinator_node_search(node, stack, hash) \
       _akinator_node_search(node, stack, hash, LOG_ARGS)      

#define akinator_get_definition(tree, node_name) \
       _akinator_get_definition(tree, nide_name, LOG_ARGS)

#define show_definition(node, stack, output) \
       _show_definition(node, stack, output, LOG_ARGS)

//===================================================================

int _show_definition(struct Node* node, struct Stack* stack, FILE* output, LOG_PARAMS);

int _akinator_get_definition(struct Tree* tree, const char* node_name, 
                                                          LOG_PARAMS);

Node* _akinator_tree_search(struct Tree* tree, struct Stack* stack, int64_t hash, LOG_PARAMS);

Node* _akinator_node_search(struct Node* node, struct Stack* stack, int64_t hash, LOG_PARAMS);

int _akinator_tree_validator(struct Tree* tree, LOG_PARAMS);

int _akinator_node_validator(struct Node* node, LOG_PARAMS);

int _akinator_tree_ctor(struct Tree* tree, LOG_PARAMS);

int _buffer_dump(struct Buffer_struct* buffer_struct, LOG_PARAMS);

int _akinator_init_base(struct Tree* tree, struct Text* text, const char* filename, 
                                                                       LOG_PARAMS);

int _buffer_struct_init(struct Buffer_struct* buffer_struct, char* buffer, 
                                           int size, int pos, LOG_PARAMS);

int _tree_read_from_file(struct Tree* tree, struct Text* text, const char* filename, 
                                                                        LOG_PARAMS);

int _node_read_from_buffer(struct Node* node, struct Buffer_struct* buffer_struct, 
                                                                      LOG_PARAMS);

//===================================================================