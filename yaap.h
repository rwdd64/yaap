#ifdef YAAP_IMPLEMENTATION
#include <string.h>
#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif

typedef enum {
	OPT_BOOL,
	OPT_VALUE
} yaap_opt_type_e;

typedef struct {
	char* identifier;
	yaap_opt_type_e type;
	void* output_ptr;
} yaap_option_t;

typedef enum {
    POSIX_STYLE,
    GNU_STYLE
} yaap_parser_style_e;

typedef struct {
	int max_options;
    int option_count;
	yaap_parser_style_e style;
	yaap_option_t* options;
} yaap_parser_t;

int yaap_reg_opt_struct(yaap_parser_t* parser_ptr, yaap_option_t option);
int yaap_reg_opt(yaap_parser_t* parser_ptr, char* identifier, int opt_type, void* output_ptr);
int yaap_run(yaap_parser_t* parser_ptr, int argc, char** argv);
int yaap_parser_init(yaap_parser_t* parser_ptr);
int yaap_parser_clean(yaap_parser_t* parser_ptr);

int yaap_reg_opt_struct(yaap_parser_t* parser_ptr, yaap_option_t option) {
    if (parser_ptr == NULL) {
        return -1;
    }

    if (option.output_ptr == NULL) {
        return -1;
    }

    parser_ptr->options[parser_ptr->option_count++] = option;
#if defined DEBUG
    printf("Registered option %s ", option.identifier);
    printf("Type: %d ", (int)option.type);
    printf("Option Count: %d", parser_ptr->option_count);
    printf("\r\n");
#endif
    return 0;
}

int yaap_reg_opt(yaap_parser_t* parser_ptr, char* identifier, int opt_type, void* output_ptr) {
    yaap_option_t option = {
        .identifier = identifier,
        .type = opt_type,
        .output_ptr = output_ptr
    };

    yaap_reg_opt_struct(parser_ptr, option);
    return 0;
}

int yaap_run(yaap_parser_t* parser_ptr, int argc, char** argv) {
    if (parser_ptr == NULL) {
        return -1;
    }

    for (int i = 1; i < argc; ++i) {
        for (int j = 0; j < parser_ptr->option_count; ++j) {
            if (strcmp(argv[i], parser_ptr->options[j].identifier) == 0) {
#if defined DEBUG
                printf("Matched option '%s' at index %d",
                        parser_ptr->options[j].identifier, i);
                printf("\r\n");
#endif
                if (parser_ptr->options[j].type == OPT_BOOL) {
                    *(int*)parser_ptr->options[j].output_ptr = 1;
                } else if (parser_ptr->options[j].type == OPT_VALUE) {
                    *(char**)parser_ptr->options[j].output_ptr = argv[i+1];
                    i++;
                }
                break;
            }
        }
    }
    return 0;
}

int yaap_parser_init(yaap_parser_t* parser_ptr) {
    parser_ptr->options = malloc(sizeof(yaap_option_t) * parser_ptr->max_options);
    if (parser_ptr->options == NULL) {
        return -1;
    }
    return 0;
}

int yaap_parser_clean(yaap_parser_t* parser_ptr) {
    free(parser_ptr->options);
    return 0;
}

#endif
