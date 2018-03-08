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

int verif_in_ll(champ_t *champ, char **name_champ, int number)
{
	while (champ->next != NULL) {
		if (champ->program_number == number) {
			champ->alive = 1;
			*name_champ = my_strdup(champ->program_name);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}

int operate_live(champ_t *champ, pc_t *pc, byte *tab)
{
	int num_champ = get_int(tab + ((pc->idx + 1) % MEM_SIZE));
	char *name_champ = NULL;

	if (verif_in_ll(champ, &name_champ, (num_champ)) == 1)
		my_printf(LIVE"\n", (num_champ), name_champ);
	return (4);
}