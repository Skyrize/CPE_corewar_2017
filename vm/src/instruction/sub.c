/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int operate_sub(champ_t *champ, pc_t *pc, byte *tab)
{
	int result_add = 0;
	int num_of_registre = 0;

	result_add = (*(tab + pc->idx + 1) - *(tab + pc->idx + 2));
	num_of_registre = *(tab + pc->idx + 3);
	assign_add_value_to_register(result_add, num_of_registre, champ, pc);
	return (4);
}