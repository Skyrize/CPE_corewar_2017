/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** NULL
*/

#include "vm.h"

void fill_memory_zone(char *vm, char *path, int idx, int size)
{
	int fd = open(path, O_RDONLY);

	lseek(fd, 4 + PROG_NAME_LENGTH + 11 + COMMENT_LENGTH + 1, SEEK_SET);
	for (int i = 0; i < size; i++)
		read(fd, &vm[i + idx], size);
	close(fd);
}

void memory_allocation_to_champs(unsigned char *vm, champ_t *champs,
						int nb_champs, char **path)
{
	int pc = 0;

	for (int i = 0; i < MEM_SIZE; i++)
		vm[i] = 0;
	for (int i = 0; i < nb_champs; i++) {
		pc = MEM_SIZE * i / nb_champs;
		champs->pc->idx = pc;
		fill_memory_zone(vm, path[i], pc, champs->size);
		champs = champs->next;
	}
}