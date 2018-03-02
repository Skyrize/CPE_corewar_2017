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

#define LIVE "The player %d(%s)is alive."
typedef unsigned char byte;

union number {
	int nbr;
	char str[4];
};

union short_number {
	int nbr;
	char str[2];
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
int get_int(byte *);
int get_short_int(byte *);
int reverse_int(int);
int reverse_short_int(int);
void memory_allocation_to_champs(unsigned char *, champ_t *, int, char **);
char *int_to_bin(unsigned int);
int *assign_value_to_parameters(char *, int *);
int *detect_parameters(int);
int get_op(byte);
void set_all_champs_pc_countdown(champ_t *, unsigned char *);
void set_pc_countdown(pc_t *, unsigned char *);
int operate_ld(champ_t *, pc_t *, byte *);
int operate_sub(champ_t *, pc_t *, byte *);
int operate_live(champ_t *, pc_t *, byte *);
int operate_zjmp(champ_t *, pc_t *, byte *);
void assign_new_value_to_new_registre(int, int, champ_t *, pc_t *);
int operate_lld(champ_t *, pc_t *, byte *);