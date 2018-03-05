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

int verif_in_ll(champ_t *champ, char *name_champ, int number)
{
	while (champ->next != NULL) {
		if (champ->program_number == number) {
			champ->alive = 1;
			name_champ = my_strdup(champ->program_name);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}

int operate_live(champ_t *champ, pc_t *pc, byte *tab)
{
	byte *num_champ = malloc(4);
	char *name_champ = NULL;
	int j = 0;

	for (int i = pc->idx ; i != pc->idx + 4 ; i++)
		num_champ[j++] = tab[i];
	if (verif_in_ll(champ, name_champ, get_int(num_champ)) == 1)
		my_printf(LIVE, get_int(num_champ), name_champ);
	free(num_champ);
	return (pc->idx + 4);
}