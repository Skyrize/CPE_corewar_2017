/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int operate_zjmp(champ_t *champ, pc_t *pc, byte *tab)
{
	int length_jump = 0;

	while (champ->next != NULL) {
		if (pc->champ_owner == champ->program_number && champ->carry == 1) {
			length_jump = get_short_int(tab + pc->idx);
			return ((length_jump % IDX_MOD) + 2);
		}
		champ = champ->next;
	}
	return (2);
}