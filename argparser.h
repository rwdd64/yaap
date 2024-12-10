#pragma once

typedef enum {
    TKN_ARG,
    TKN_OPT,
} token_type_e;

typedef enum {
    OPT_SINGLE,
    OPT_ARG,
} option_type_e;

typedef struct {
    option_type_e type;
    char* identifier;
} option_t;

typedef struct {
    option_t options[256];
    int option_count;
} argparser_t;

int add_option(argparser_t* parser, option_t option);
int parse_args(argparser_t* parser, int argc, char** argv);
