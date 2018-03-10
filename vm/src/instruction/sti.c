/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

/*
{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
*/
int how_much_read(int *parameters)
{
	int param_0 = 0;
	int param_1 = 0;
	int param_2 = 0;

	parameters[0] == 1 ? param_0 += 1 : 0;
	parameters[0] == 2 ? param_0 += 2 : 0;
	parameters[0] == 4 ? param_0 += 2 : 0;
	parameters[1] == 1 ? param_1 += 1 : 0;
	parameters[1] == 2 ? param_1 += 2 : 0;
	parameters[1] == 4 ? param_1 += 2 : 0;
	parameters[2] == 1 ? param_2 += 1 : 0;
	parameters[2] == 2 ? param_2 += 2 : 0;
	parameters[2] == 4 ? param_2 += 2 : 0;
	return (param_0 + param_1 + param_2);
}

int check_parameters_sti(int *parameters)
{
	if ((parameters[0] == 1)
	|| (parameters[1] == 1 || parameters[1] == 2 || parameters[1] == 4)
	|| (parameters[2] == 1 || parameters[2] == 2))
		return (0);
	return (84);
}

void put_to_adress(champ_t *champ, pc_t *pc,
int *param, byte *tab)
{
	union number reg;
	int number = get_register_value(pc, champ, *(tab + pc->idx + 2
	% MEM_SIZE));

	//my_printf("adress : %d\n", param[3]);
	reg.nbr = reverse_int(number);
	for (int i = 0 ; i < 4 ; i++) {
		//my_printf("str %d : %d\n", i, reg.str[i]);
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
	int new_num = 0;
	int return_value = 0;

	if (param[1] == T_REG) {
		return_value = get_register_value(pc, champ, (*(tab + pc->idx +
		param[3]) % MEM_SIZE));
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
		get_num = get_short_int(tab + ((pc->idx +
		param[3]) % MEM_SIZE));
		new_num = get_int(tab + (IDX_ADRESS) % MEM_SIZE));
		param[3] += 2;
		return (new_num);
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

int check_reg_sti(int *param, int first, int second, int third)
{
	if ((param[0] == T_REG && (first < 1 || first > 16)) ||
	(param[1] == T_REG && (second < 1 || second > 16)) ||
	(param[2] == T_REG && (third < 1 || third > 16)))
		return (84);
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
		return (how_much_read(parameters));
	final_param[3] = (value_second_param + value_third_param);
	put_to_adress(champs, pc, final_param, tab);
	return (how_much_read(parameters));
}