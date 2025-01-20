#include <stdio.h>
#include <stdbool.h>

#define YAAP_IMPLEMENTATION
#include "../yaap.h"

int main(int argc, char** argv) {
    bool a = false;
    char* b = NULL;

    yaap_parser_t parser = {
        .style = GNU_STYLE,
        .max_options = 16
    };
    
    yaap_parser_init(&parser);

    yaap_reg_opt(&parser, "--opt1", OPT_BOOL, &a);
    yaap_reg_opt(&parser, "-a", OPT_BOOL, &a);
    yaap_reg_opt(&parser, "--opt2", OPT_VALUE, &b);
    yaap_reg_opt(&parser, "-b", OPT_VALUE, &b);

    yaap_run(&parser, argc, argv);

    yaap_parser_clean(&parser);

    printf("Values\n");
    printf("============\n");
    printf("Option 1: %d\n", a);
    printf("Option 2: %s\n", b==NULL ? "Null" : b);

    return 0;
}
