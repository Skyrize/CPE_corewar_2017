/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void assign_add_value_to_register(int result_add, int num_of_registre,
						champ_t *champ, pc_t *pc)
{
	int check_pn_co = 0;

	while (champ->next != NULL) {
		if (champ->program_number == pc->champ_owner
		&& (T_REG >= 1 && T_REG <= 16)) {
			champ->reg[num_of_registre] = result_add;
			check_pn_co = 1;
			break;
		}
		champ = champ->next;
	}
	if (check_pn_co == 1 && (T_REG >= 1 && T_REG <= 16)
	&& C_CARRY == false)
		C_CARRY = true;
	else if ((T_REG < 1 || T_REG > 16))
		C_CARRY = false;
}


int operate_add(champ_t *champ, pc_t *pc, byte *tab)
{
	int result_add = 0;
	int num_of_registre = 0;

	result_add = (*(tab + pc->idx + 1) + *(tab + pc->idx + 2));
	num_of_registre = *(tab + pc->idx + 3);
	assign_add_value_to_register(result_add, num_of_registre, champ, pc);
	return (4);
}