/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int compute_bytes_read_lldi(int *params)
{
	int param_0 = 0;
	int param_1 = 0;
	int param_2 = 0;
	static int i = 0;

	i += 1;
	params[0] == 1 ? param_0 += 1 : 0;
	params[0] == 2 ? param_0 += 2 : 0;
	params[0] == 4 ? param_0 += 2 : 0;
	params[1] == 1 ? param_1 += 1 : 0;
	params[1] == 2 ? param_1 += 2 : 0;
	params[1] == 4 ? param_1 += 2 : 0;
	params[2] == 1 ? param_2 += 1 : 0;
	params[2] == 2 ? param_2 += 2 : 0;
	params[2] == 4 ? param_2 += 2 : 0;
	if (i == 2)
		free(params);
	return (param_0 + param_1 + param_2);
}

int compute_parameter_lldi(int param)
{
	if (param == 1)
		return (1);
	return (2);
}

int parameter_lldi(byte *tab, int param, pc_t *pc, champ_t *champs)
{
	int get_num = get_short_int(tab + ((pc->idx + 2) % MEM_SIZE));
	int new_num = get_int(tab + ((pc->idx + get_num) % MEM_SIZE));

	if (param == 1)
		return (get_register_value(pc, champs, \
					*(tab + (pc->idx + 2) % MEM_SIZE)));
	if (param == 4)
		return (new_num);
	return (get_num);
}

int operate_lldi(champ_t *champs, pc_t *pc, byte *tab)
{
	int *params = detect_parameters(*(tab + (pc->idx + 1) % MEM_SIZE));
	int first = parameter_lldi(tab, params[0], pc, champs);
	int second = parameter_lldi(tab +
		compute_parameter_lldi(params[0]), params[1], pc, champs);
	int reg = *(tab + (pc->idx + compute_bytes_read_lldi(params) + 1)
		% MEM_SIZE);
	int res = first + second;

	if (params[2] != T_REG || reg < 1 || reg > 16)
		return (compute_bytes_read_lldi(params) + 1);
	assign_new_value_to_new_registre(get_int(tab + pc->idx + res)
						% MEM_SIZE, reg, champs, pc);
	return (compute_bytes_read_lldi(params) + 1);
}