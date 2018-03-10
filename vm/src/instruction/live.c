/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int char_to_int(byte *num_champ)
{
	return (*((int *)num_champ));
}

int verif_in_ll(champ_t *champ, char **name_champ, int number, memory_t *memory)
{
	while (champ) {
		if (champ->program_number == number) {
			champ->alive = 1;
			memory->last_alive = number;
			*name_champ = my_strdup(champ->program_name);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}

int operate_live(champ_t *champ, pc_t *pc, memory_t *memory)
{
	int num_champ = get_int(memory->vm + ((pc->idx + 1) % MEM_SIZE));
	char *name_champ = NULL;

	if (verif_in_ll(champ, &name_champ, (num_champ), memory) == 1)
		my_printf(LIVE, (num_champ), name_champ);
	return (4);
}