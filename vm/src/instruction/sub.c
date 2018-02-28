/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void assign_add_value_to_register(int result_add, int num_of_registre, champ_t *champ, pc_t *pc)
{
	while (champ->next != NULL) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[num_of_registre] = result_add
			champ->carry = true;
		}
		champ = champ->next;
	}
}


int operate_sub(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(my_getnbr(tab + pc->idx + 1));
	int result_add = 0;
	int num_of_registre = 0;

	if (parameters[0] != T_REG && parameters[1] != T_REG
	&& parameters[2] != T_REG)
		return;
	result_add = ((tab + pc->idx + 1) - (tab + pc->idx + 2));
	num_of_registre = my_getnbr(tab + pc->idx + 3);
	assign_add_value_to_register(result_add, num_of_registre, champ, pc);
	return (pc->idx + 4);
}