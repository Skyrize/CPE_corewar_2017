/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void assign_champ_carry_false(champ_t *champ, pc_t *pc)
{
	while (champ) {
		if (champ->program_number == pc->champ_owner)
			champ->carry = false;
		champ = champ->next;
	}
}

void assign_champ_carry_true(champ_t *champ, pc_t *pc)
{
	while (champ) {
		if (champ->program_number == pc->champ_owner)
			champ->carry = true;
		champ = champ->next;
	}
}