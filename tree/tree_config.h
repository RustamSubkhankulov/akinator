#pragma once

#include <cstddef>

#define TEMP_DIR "/mnt/c/users/rust2/appdata/local/temp/"

//===================================================================

 const int Dir_name_size = 100;

 const int System_cmnd_buf_size = 200;

//===================================================================

//TREE PARAMETERS

//Element type of the list structure
typedef const char * elem_t;

//Name of type using in list(for logs)
#define TYPE_NAME "const char*"

//Specificator for type using in list
#define ELEM_SPEC "%s"

//===================================================================

//TREE OPTIONS

#define TREE_VERIFICATE

//Logs for tree
//Generates .png files in /images and list_logs.html in text_files/
#define TREE_LOGS

//Calls dump of the tree every time validator is called
#define TREE_DEBUG

//Hash protection for tree
#define TREE_HASH

//GRAPHVIZ
#define TREE_GRAPHVIZ

//==================================================================

//SUPPORTING DEFINITIONS

const unsigned Poison_value = 228;

//==================================================================