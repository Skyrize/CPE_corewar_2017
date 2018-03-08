/*
** EPITECH PROJECT, 2017
** asm
** File description:
** asm.h created: 12/02/18 18:44
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdbool.h>
#include "op.h"

#define ERROR_INT 42910

typedef char byte;

union four_bytes_union {
	int i;
	char str[4];
};

union two_bytes_union {
	short i;
	char str[2];
};

struct cmd_data_s{
	char *name;
	char *description;
};

struct instruction_s {
	byte instruction_code;
	int coding_byte;
	int nbr_args;
	args_type_t *args_types;
	int *args;
	struct instruction_s *next;
};

struct label_s {
	char *name;
	int bytes_pos;
	struct label_s *next;
};

typedef struct cmd_data_s cmd_data;
typedef struct instruction_s instruction_t;
typedef struct label_s label_t;

/// get the file descriptor of the file
///
/// the first call must be with the filename, after that, just put NULL in arg
/// \param name filename
/// \return file descriptor of the file
int get_fd(char *name);

void check_syntax(void);

bool is_line_valid(char *line);

char *comma_to_spaces(char *line);

char *tab_to_spaces(char *line);

void clean_str_asm(char **line);

/// revert all the bytes of an int
/// \param nbr int
/// \return reverted int
int revert_int(int nbr);

/// revert 2 bytes of short
/// \param nbr short
/// \return reverted short
short revert_short(short nbr);

bool check_unknown_line(char **words);

bool is_valid_cmd(char **words);

/// return the content of .name and .comment
/// \param line
/// \return str
char *get_cmd_str(char *line);

/// if .s -> .cor and if .other -> .other.cor
/// \param source_filename
/// \return file descriptor
int create_file(char *source_filename);

/// put the magic bytes
/// \param fd file descriptor
void put_header(int fd);

cmd_data *get_cmd_data(void);

/// Check if first word is cmd
bool is_label(char **words);

int get_param_bytecode(char **words, int param_nbr);

char **get_words_without_label(char **words);

int get_fnc_idx(char *fnc_name);

/// Return a null terminated array of args_type_t (T_REG, T_DIR, T_IND)
args_type_t *get_args_types(char **words);

byte get_args_nbr(char **words);

/// return adress of the adress of the first node
instruction_t **get_instructions(void);

instruction_t *add_operation_to_list(instruction_t *instruction);

bool is_there_a_command(char **words);

instruction_t *create_operation(char **words);

void process_instruction_line(char **words);

void log_double_string_array(char **str);

/// add and return the value
int counter(int to_add);

/// warning use with pre formatted words
int get_arg(char *str, args_type_t arg_type);

/// WARNING use with pre formatted words
int *get_operation_args(char **words, args_type_t *args_types);

#endif /* !ASM_H_ */
