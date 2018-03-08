/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void change_carry_and(champ_t *champ, int *all_value)
{
	if (all_value[0] & all_value[1] != 0)
		champ->carry = true;
	else
		champ->carry = false;
}

int assign_to_last_register(int *all_value, champ_t *champ, pc_t *pc)
{
	if (all_value[0] == -1 || all_value[2] < 1 || all_value[2] > 16)
		return (84);
	while (champ) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[all_value[2] - 1] =
			all_value[0] & all_value[1];
			change_carry_and(champ, all_value);
		}
		champ = champ->next;
	}
	return (0);
}

int parameters_zero(int *parameters, byte *tab, pc_t *pc, champ_t *champ)
{
	int t_reg_value = *(tab + ((pc->idx + 2) % MEM_SIZE));
	int get_num = 0;
	int new_num = 0;

	if (parameters[0] == T_REG) {
		parameters[3] = 3;
		return (t_reg_value >= 1 && t_reg_value <= 16 ?
		get_register_value(pc, champ, t_reg_value) : -1);
	} else if (parameters[0] == T_DIR) {
		parameters[3] = 6;
		return (get_int(tab + ((pc->idx + 2) % MEM_SIZE)));
	}
	if (parameters[0] == T_IND) {
		parameters[3] = 4;
		get_num = get_short_int(tab + ((pc->idx + 2) % MEM_SIZE));
		new_num = get_int(tab + (IDX_ADRESS) % MEM_SIZE));
		return (new_num);
	}
	return (0);
}

int parameters_two(int *parameters, byte *tab, pc_t *pc, champ_t *champ)
{
	int t_reg_value = *(tab + ((pc->idx + parameters[3]) % MEM_SIZE));
	int get_num = 0;
	int new_num = 0;

	if (parameters[1] == T_REG)
		return (t_reg_value >= 1 && t_reg_value <= 16 ?
		get_register_value(pc, champ, t_reg_value) : -1);
	else if (parameters[1] == T_DIR)
		return (get_int(tab + ((pc->idx + parameters[3]) % MEM_SIZE)));
	if (parameters[1] == T_IND) {
		get_num = get_short_int(tab + ((pc->idx + parameters[3])
		% MEM_SIZE));
		new_num = get_int(tab + (IDX_ADRESS)
		% MEM_SIZE));
		return (new_num);
	}
	return (0);
}

int operate_and(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab
	+ ((pc->idx + 1) % MEM_SIZE)));
	int *final_parameters = fill_parameters_and_instruct(parameters);
	int *all_value = malloc(sizeof(int) + 3);
	if (check_parameters_and_instruct(parameters, champ, pc, 0) == 1)
		return (1);
	all_value[0] = parameters_zero(final_parameters, tab, pc, champ);
	all_value[1] = parameters_two(final_parameters, tab, pc, champ);
	all_value[2] = *(tab + ((pc->idx +
	compute_bytes_read(champ, pc, parameters) + 1)));
	all_value[2] < 1 || all_value[2] > 16 ? all_value[2] = -1 : 0;
	if (check_parameters_and_instruct(all_value, champ, pc, 1) == 1)
		return (1);
	if (assign_to_last_register(all_value, champ, pc) == 84)
		assign_champ_carry_false(champ, pc);
	return (0);
}