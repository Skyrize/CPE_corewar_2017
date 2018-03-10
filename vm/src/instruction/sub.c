/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int operate_sub(champ_t *champ, pc_t *pc, byte *tab)
{
	int result_sub = 0;
	int num_of_registre = 0;
	int a = get_register_value(pc, champ,
	*(tab + ((pc->idx + 2) % MEM_SIZE)));
	int b = get_register_value(pc, champ,
	*(tab + ((pc->idx + 3) % MEM_SIZE)));

	result_sub = (a - b);
	num_of_registre = *(tab + ((pc->idx + 4) % MEM_SIZE));
	if (num_of_registre < 1 || num_of_registre > 16)
		return (3);
	assign_result_operation_to_register(result_sub, num_of_registre,
	champ, pc);
	return (3);
}