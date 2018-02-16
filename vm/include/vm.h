/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#include "my.h"
#include "op.h"
#include <fcntl.h>

typedef struct pc_s {
	int idx;
	int countdown;
	struct pc_s *next;
} pc_t;

typedef struct champ_s {
	int program_number;
	int reg[REG_NUMBER];
	int size;
	bool carry;
	char *program_name;
	pc_t *pc;
	struct champ_s *next;
} champ_t;

union data {
	int nbr;
	char str[4];
};

void set_champs_info(champ_t *, int , char **);
char *get_str(int);
int get_int(int);