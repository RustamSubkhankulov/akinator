#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"
#include "errors_and_logs.h"

int main(int argc, char* argv[]) {

    int err = 0;

    FILE* logs_file = open_log_file(argv[1]);

    struct Stack stack = { 0 };

    stack_ctor(&stack);

    stack_push(&stack, 10);

    stack_pop(&stack, &err);

    stack_dtor(&stack);

    close_log_file(logs_file);
}