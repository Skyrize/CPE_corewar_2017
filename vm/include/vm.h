/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#include "my.h"
#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

typedef byte char;

union number {
	int nbr;
	char str[4];
};

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
	bool alive;
	char *program_name;
	pc_t *pc;
	struct champ_s *next;
} champ_t;

typedef struct memory_s {
	char memory[MEM_SIZE];
	int owner[MEM_SIZE];
} memory_t;


champ_t *set_champs_info(champ_t *, int , char **);
char *get_str(int);
int get_int(int);
int reverse_int(int);
void memory_allocation_to_champs(memory_t *, champ_t *, int);
char *int_to_bin(unsigned int);
int *assign_value_to_parameters(char *, int *);
int *detect_parameters(int);