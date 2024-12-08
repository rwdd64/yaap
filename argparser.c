#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "argparser.h"

argparser_t* new_parser() {
    argparser_t parser;
    return memset(&parser, 0, sizeof(parser));
}

int add_option(argparser_t* parser, option_t option) {
    parser->options[parser->option_count++] = option;
#if defined DEBUG
    printf("Added option '%s'\n", option.identifier);
    printf("Type: '%d'\n", (int)option.type);
    printf("Option Count: '%d'\n", parser->option_count);
    printf("\r\n");
#endif
}

int parse_args(argparser_t* parser, int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; j < parser->option_count; ++j) {
            if (strcmp(argv[i], parser->options[j].identifier) == 0) {
#if defined DEBUG
                printf("Matched option '%s' at index %d\n",
                        parser->options[j].identifier, i);
                printf("\r\n");
#endif
            }
        }
    }
}

