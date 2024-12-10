#pragma once

#define MAX_OPTIONS 256

typedef enum {
    TKN_ARG,
    TKN_OPT,
} token_type_e;

typedef enum {
    OPT_BOOL,
    OPT_VAL,
} option_type_e;

typedef struct {
    option_type_e type;
    char* identifier;
} option_t;

typedef struct {
    option_t options[MAX_OPTIONS];
    int option_count;
} argparser_t;

typedef struct {
    void* values[MAX_OPTIONS];
} result_t;

int add_option(argparser_t* parser, option_t option);
int parse_args(argparser_t* parser, int argc, char** argv, result_t* result);
