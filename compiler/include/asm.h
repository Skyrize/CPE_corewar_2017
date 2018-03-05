/*
** EPITECH PROJECT, 2017
** asm
** File description:
** asm.h created: 12/02/18 18:44
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdbool.h>

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

struct tag_s{
	char *name;
	struct tag_s* next;
};

typedef char byte;
typedef struct cmd_data_s cmd_data;
typedef struct tag_s tag_t;

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

#endif /* !ASM_H_ */
