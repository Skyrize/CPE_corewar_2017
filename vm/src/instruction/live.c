/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"

void operate_live(champ_t *champ, pc_t *pc, byte *tab)
{
	byte *num_champ = malloc(4);
	int j = 0;

	for (int i = pc->idx ; i != pc->indx + 4 ; i++)
		num_champ[j++] = tab[i];
	if (char_to_int(num_champ) == champ->program_number)
		my_printf("Le champion : ")
	free(num_champ);
}