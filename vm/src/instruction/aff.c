/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int find_register(champ_t *champs, pc_t *pc, char c)
{
	for (int i = 0; champs; champs = champs->next)
		if (champs->program_number == pc->champ_owner)
			break;
	return (champs->reg[c - 1] % 256);
}

int operate_aff(champ_t *champs, pc_t *pc, unsigned char *vm)
{
	int register_to_display = find_register(champs, pc, vm[0]);

	if (register_to_display >= 1 && register_to_display <= 16)
		my_printf("%c\n", register_to_display);
	return (1);
}