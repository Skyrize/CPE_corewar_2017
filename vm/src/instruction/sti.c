/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void put_to_adress(champ_t *champ, pc_t *pc,
int *param, byte *tab)
{
	union number reg;
	int number = get_register_value(pc, champ, *(tab + pc->idx + 2
	% MEM_SIZE));

	reg.nbr = reverse_int(number);
	for (int i = 0 ; i < 4 ; i++) {
		*(tab + (pc->idx + param[3] % IDX_MOD + i) % MEM_SIZE) =
		reg.str[i];
	}

}

int get_first_value(pc_t *pc, byte *tab, int *param)
{
	int register_number = (*(tab + (pc->idx + 2) % MEM_SIZE));

	param[3] += 3;
	return (register_number);
}

int get_scd_value(champ_t *champ, pc_t *pc, byte *tab, int *param)
{
	int get_num = 0;
	int return_value = 0;

	if (param[1] == T_REG) {
		return_value = get_register_value(pc, champ, STI_PARAM);
		param[3] += 1;
		return (return_value);
	}
	if (param[1] == T_DIR) {
		return_value = get_short_int(tab + ((pc->idx +
		param[3]) % MEM_SIZE));
		param[3] += 2;
		return (return_value);
	}
	if (param[1] == T_IND) {
		get_num = get_short_int(tab + STI_PARAM);
		param[3] += 2;
		return (get_int(tab + (IDX_ADRESS) % MEM_SIZE)));
	}
	return (0);
}

int get_third_value(champ_t *champ, pc_t *pc, byte *tab, int *param)
{
	int return_value = 0;

	if (param[2] == T_REG) {
		return_value = get_register_value(pc, champ, (*(tab + pc->idx +
		param[3]) % MEM_SIZE));
		return (return_value);
	}
	if (param[2] == T_DIR)
		return (get_short_int(tab + ((pc->idx + param[3]) % MEM_SIZE)));
	return (0);
}

int operate_sti(champ_t *champs, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + (pc->idx + 1) % MEM_SIZE));
	int *final_param = fill_parameters_and_instruct(parameters);
	int first_value = get_first_value(pc, tab, final_param);
	int value_second_param = get_scd_value(champs, pc, tab, final_param);
	int value_third_param = get_third_value(champs, pc, tab, final_param);

	if (check_parameters_sti(final_param) == 84 ||
	check_reg_sti(parameters, first_value, value_second_param,
	value_third_param) == 84)
		return (how_much_read_sti(parameters) + 1);
	final_param[3] = (value_second_param + value_third_param);
	put_to_adress(champs, pc, final_param, tab);
	return (how_much_read_sti(parameters) + 1);
}