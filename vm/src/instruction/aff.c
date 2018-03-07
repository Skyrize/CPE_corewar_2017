/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int find_register(champ_t *champs, pc_t *pc, char c)
{
	for (; champs; champs = champs->next) {
		if (champs->program_number == pc->champ_owner)
			break;
	}
	if (champs == NULL)
		return (0);
	return (champs->reg[c - 1] % 256);
}

int operate_aff(champ_t *champs, pc_t *pc, byte *vm)
{
	int register_to_display = 0;

	if (vm[pc->idx + 2] < 1 && vm[pc->idx + 2] > 16)
		return (2);
	register_to_display = find_register(champs, pc, vm[pc->idx + 2]);
	my_printf("%c\n", register_to_display);
	return (2);
}