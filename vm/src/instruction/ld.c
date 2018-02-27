/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void operate_ld(champ_t *champ, pc_t *pc, byte *tab)
{
	byte *num_champ = malloc(4);

	for (int i = pc->idx ; i != pc->indx + 4 ; i++)
		num_champ[j++] = tab[i];
}