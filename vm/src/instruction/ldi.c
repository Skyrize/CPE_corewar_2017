/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

// int read_t_dir_ldi(byte *tab, pc_t *pc, champ_t *champs)
// {

// }

// int read_t_ind_ldi(byte *tab, pc_t *pc, champ_t *champs)
// {

// }
/*
int get_register_value(pc_t *pc, champ_t *champs, int register_number)
{
	int register_value = 0;

	while (champs) {
		if (champs->program_number == pc->champ_owner) {
			register_value = champs->reg[register_number - 1];
			break;
		}
		champs = champs->next;
	}
	return (register_value);
}

int parameter(byte *tab, int param, pc_t *pc, champ_t *champs)
{
	int res = 0;

	if (param == 1)
		return(get_register_value(pc, champs, *(tab + pc->idx + 2)));
	return(get_short_int(tab + pc->idx + 2));
}

void operate_ldi(champ_t *champs, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + pc->idx + 1));
	int first = parameter(tab, parameters[0], pc, champs);
	int second;
	int register_number = *(tab + pc->idx +
			compute_bytes_read(parameter, champs, pc) - 1);

	if (parameters[2] != 1)
		return (compute_bytes_read(parameters, champs, pc));
	if (parameters[0] == T_REG)
		second = parameter(tab + 1, parameters[1], pc, champs);
	else
		second = parameter(tab + 2, parameters[1], pc, champs);
	if (parameters[0] != T_IND)
		return (0);
	else
		return (0);
	return (0);
}*/