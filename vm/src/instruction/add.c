/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void assign_carry(int check_pn_co, int result_add, champ_t *champ, pc_t *pc)
{
	if (check_pn_co == 1 && (T_REG >= 1 && T_REG <= 16)
	&& C_CARRY == false)
		C_CARRY = true;
	else if ((T_REG < 1 || T_REG > 16) || result_add == 0)
		C_CARRY = false;
}

void assign_result_operation_to_register(int result_add, int num_of_registre,
champ_t *champ, pc_t *pc)
{
	int check_pn_co = 0;

	while (champ) {
		if (champ->program_number == pc->champ_owner
		&& (T_REG >= 1 && T_REG <= 16)) {
			champ->reg[num_of_registre - 1] = result_add;
			check_pn_co = 1;
			break;
		}
		champ = champ->next;
	}
	assign_carry(check_pn_co, result_add, champ, pc);
}

int get_value_in_register(champ_t *champ, pc_t *pc, int value)
{
	while (champ) {
		if (champ->program_number == pc->champ_owner)
			return (champ->reg[value - 1]);
		champ = champ->next;
	}
	return (0);
}

int operate_add(champ_t *champ, pc_t *pc, byte *tab)
{
	int result_add = 0;
	int num_of_registre = 0;
	int a = get_register_value(pc, champ,
	*(tab + ((pc->idx + 2) % MEM_SIZE)));
	int b = get_register_value(pc, champ,
	*(tab + ((pc->idx + 3) % MEM_SIZE)));

	result_add = (a + b);
	num_of_registre = *(tab + ((pc->idx + 4) % MEM_SIZE));
	if (num_of_registre < 1 || num_of_registre > 16)
		return (3);
	assign_result_operation_to_register(result_add, num_of_registre,
	champ, pc);
	return (3);
}