/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** NULL
*/

#include "vm.h"

void check_magic_number(int fd, char *champion)
{
	int magic_number;

	read(fd, &magic_number, 4);
	magic_number = reverse_int(magic_number);
	if (magic_number != COREWAR_EXEC_MAGIC) {
		my_printf("%s : Invalid Champion\n", champion);
		exit(84);
	}
}

void get_header(champ_t *champ, int fd, int champ_number)
{
	int read_bytes = 0;

	champ->program_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	read_bytes = read(fd, champ->program_name, PROG_NAME_LENGTH);
	champ->program_name[read_bytes] = 0;
	champ->program_number = champ_number;
	champ->reg[0] = champ_number;
	lseek(fd, 4, SEEK_CUR);
	read(fd, &champ->size, 4);
	champ->size = reverse_int(champ->size);
	lseek(fd, COMMENT_LENGTH, SEEK_CUR);
}

void init_pc(pc_t *pc, int owner)
{
	pc->idx = 0;
	pc->countdown = 0;
	pc->champ_owner = owner;
	pc->next = NULL;
}

void add_to_list(champ_t *champs, char *pathname, int fd, int champ_number)
{
	champ_t *tmp = malloc(sizeof(*tmp));

	while (champs->next != NULL)
		champs = champs->next;
	check_magic_number(fd, pathname);
	get_header(tmp, fd, champ_number);
	tmp->carry = 0;
	tmp->alive = 0;
	for (int i = 1; i < REG_NUMBER; i++)
		tmp->reg[i] = 0;
	tmp->pc = malloc(sizeof(*tmp->pc));
	init_pc(tmp->pc, tmp->program_number);
	tmp->next = NULL;
	champs->next = tmp;
}

champ_t *set_champs_info(champ_t *champs, int nb_champs, char **str)
{
	int fd = open(str[1], O_RDONLY);

	champs = malloc(sizeof(*champs));
	check_magic_number(fd, str[1]);
	get_header(champs, fd, 1);
	champs->carry = 0;
	champs->alive = 0;
	for (int i = 1; i < REG_NUMBER; i++)
		champs->reg[i] = 0;
	champs->pc = malloc(sizeof(*champs->pc));
	init_pc(champs->pc, champs->program_number);
	champs->next = NULL;
	close(fd);
	for (int i = 2; i < nb_champs + 1; i++) {
		fd = open(str[i], O_RDONLY);
		add_to_list(champs, str[i], fd, i);
		close(fd);
	}
	return (champs);
}
