/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#include "my.h"

typedef struct pc_s {
	int idx;
	struct pc_s *next;
} pc_t;

typedef struct champ_s {
	int program_number;
	int reg[REG_NUMBER];
	int size;
	bool carry;
	char *program_name;
	pc_t *pc;
} champ_t;