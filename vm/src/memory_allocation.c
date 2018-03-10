/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** NULL
*/

#include "vm.h"

int fill_memory_zone(unsigned char *vm, char *path, int idx, int size)
{
	int fd = open(path, O_RDONLY);
	int i = 0;

	lseek(fd, 4 + PROG_NAME_LENGTH + 11 + COMMENT_LENGTH + 1, SEEK_SET);
	for (i = 0; i < size; i++)
		if (read(fd, &vm[i + idx], 1) <= 0)
			break;
	if (i != size)
		return (84);
	close(fd);
	return (0);
}

int memory_allocation_to_champs(unsigned char *vm, champ_t *champs,
						int nb_champs, char **path)
{
	int pc = 0;

	for (int i = 0; i < MEM_SIZE; i++)
		vm[i] = 0;
	for (int i = 0; i < nb_champs; i++) {
		pc = MEM_SIZE * i / nb_champs;
		champs->pc->idx = pc;
		if (fill_memory_zone(vm, path[i], pc, champs->size) == 84) {
			my_printf("%s : Invalid Champion\n",
							champs->program_name);
			return (84);
		}
		champs = champs->next;
	}
	return (0);
}