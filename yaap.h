#pragma once

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
