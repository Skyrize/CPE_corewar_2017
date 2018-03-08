/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int *change_parameters_ldi(int *parameters)
{
	for (int i = 0; i < 2; i++) {
		if (parameters[i] == 4)
			parameters[i] = 2;
	}
	return (parameters);
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

int first_parameter_ldi(byte *tab, int param, pc_t *pc, champ_t *champs)
{
	if (param == 1)
		return(get_register_value(pc, champs, \
					*(tab + (pc->idx + 2) % MEM_SIZE)));
	return(get_short_int(tab + (pc->idx + 2) % MEM_SIZE));
}

int second_parameter_ldi(byte *tab, int *params, pc_t *pc, champ_t *champs)
{
	if (params[0] == 1 && params[1] == 1)
		return(get_register_value(pc, champs, \
					*(tab + (pc->idx + 3) % MEM_SIZE)));
	else if (params[0] != 1 && params[1] == 1)
		return(get_register_value(pc, champs, \
					*(tab + (pc->idx + 4) % MEM_SIZE)));
	else if (params[0] != 1 && params[1] != 1)
		return(get_short_int(tab + (pc->idx + 4) % MEM_SIZE));
	return(get_short_int(tab + (pc->idx + 4) % MEM_SIZE));
}

int operate_ldi(champ_t *champs, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + (pc->idx + 1) % MEM_SIZE));
	int first;
	int second;
	int reg_number;

	parameters = change_parameters_ldi(parameters);
	first = first_parameter_ldi(tab, parameters[0], pc, champs);
	reg_number = *(tab +
	(pc->idx + compute_bytes_read(parameters, champs, pc) + 1) % MEM_SIZE);
	if (parameters[2] != 1)
		return (compute_bytes_read(parameters, champs, pc) + 1);
	second = second_parameter_ldi(tab, parameters, pc, champs);
	if (parameters[0] != T_IND)
		assign_new_value_to_new_registre(get_int(tab + \
		(pc->idx + first + second) % MEM_SIZE), reg_number, champs, pc);
	else
		assign_new_value_to_new_registre(get_int(tab + (pc->idx +
		get_int(tab + (pc->idx + first) % MEM_SIZE) + second)
		% MEM_SIZE), reg_number, champs, pc);
	return (compute_bytes_read(parameters, champs, pc) + 1);
}
