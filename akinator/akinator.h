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

//===================================================================

int _buffer_dump(struct Buffer_struct* buffer_struct, LOG_PARAMS);

int _akinator_init_base(struct Tree* tree, struct Text* text, const char* filename, LOG_PARAMS);

int _buffer_struct_init(struct Buffer_struct* buffer_struct, char* buffer, 
                                           int size, int pos, LOG_PARAMS);

int _tree_read_from_file(struct Tree* tree, struct Text* text, const char* filename, LOG_PARAMS);

int _node_read_from_buffer(struct Node* node, struct Buffer_struct* buffer_struct, 
                                                                      LOG_PARAMS);

//===================================================================