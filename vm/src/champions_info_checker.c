/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"

int check_champs_live(champ_t *champs)
{
	unsigned int i = 0;
	champ_t *tmp = champs;

	while (tmp) {
		if (tmp->alive == 1)
			i++;
		else
			tmp->pc = NULL;
		tmp = tmp->next;
	}
	return (i);
}

int get_register_value(pc_t *pc, champ_t *champs, int reg_number)
{
	int register_value = 0;

	while (champs) {
		if (champs->program_number == pc->champ_owner) {
			register_value = champs->reg[reg_number - 1];
			break;
		}
		champs = champs->next;
	}
	return (register_value);
}