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

typedef char byte;

union number {
	int nbr;
	char str[4];
};

typedef struct memory_s {
	unsigned char *vm;
	int nbr_live;
} memory_t;

typedef struct pc_s {
	int idx;
	int countdown;
	int champ_owner;
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

champ_t *set_champs_info(champ_t *, int , char **);
char *get_str(int);
int get_int(int);
int reverse_int(int);
void memory_allocation_to_champs(unsigned char *, champ_t *, int, char **);
char *int_to_bin(unsigned int);
int *assign_value_to_parameters(char *, int *);
int *detect_parameters(int);