/*
** EPITECH PROJECT, 2018
** nul
** File description:
** null
*/

#include "vm.h"

int get_param_st(pc_t *pc, byte *tab, int *parameters)
{
	int ind = get_short_int(tab + (pc->idx + 3) % MEM_SIZE);

	if (parameters[1] == T_IND)
		return (ind);
	return (*(tab + (pc->idx + 3) % MEM_SIZE));
}

void reg_case_st(champ_t *champs, pc_t *pc, int *params, byte *tab)
{
	int register_number = *(tab + (pc->idx + 2) % MEM_SIZE);
	int param_2 = get_param_st(pc, tab, params);

	register_number = get_register_value(pc, champs, register_number);
	assign_new_value_to_new_registre(register_number, param_2, champs, pc);
}

void ind_case_st(champ_t *champs, pc_t *pc, int *params, byte *tab)
{
	int register_number = *(tab + (pc->idx + 2) % MEM_SIZE);
	int param_2 = get_param_st(pc, tab, params);
	union number reg;

	reg.nbr = get_register_value(pc, champs, register_number);
	reg.nbr = reverse_int(reg.nbr);
	for (int i = 0; i < 4; i++)
		*(tab + (pc->idx + param_2 % IDX_MOD + i) % MEM_SIZE) =
		reg.str[i];
}

int operate_st(champ_t *champs, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + (pc->idx + 1) % MEM_SIZE));
	int ret = 0;

	if (parameters[0] != T_REG) {
		assign_champ_carry_false(champs, pc);
		free(parameters);
		return (compute_bytes_read(champs, pc, parameters) + 1);
	}
	if (parameters[1] == T_IND) {
		ind_case_st(champs, pc, parameters, tab);
		free(parameters);
		return (compute_bytes_read(champs, pc, parameters) + 1);
	}
	reg_case_st(champs, pc, parameters, tab);
	ret = compute_bytes_read(champs, pc, parameters) + 1;
	free(parameters);
	return (ret);
}