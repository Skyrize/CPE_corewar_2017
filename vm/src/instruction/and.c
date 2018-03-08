/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int check_parameters(int *parameters)
{
	if ((parameters[0] == 1 || parameters[0] == 2 || parameters[0] == 4)
	&& (parameters[1] == 1 || parameters[1] == 2 || parameters[1] == 4)
	&&(parameters[2] == 1))
		return (0);
	return (84);
}

int assign_to_last_register(int *all_value, champ_t *champ, pc_t *pc)
{
	if (all_value[0] == -1 || all_value[2] < 1 || all_value[2] > 16)
		return (84);
	while (champ) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[all_value[2] - 1] =
			all_value[0] & all_value[1];
			champ->carry = true;
		}
		champ = champ->next;
	}
	return (0);
}

int parameters_zero(int *parameters, byte *tab, pc_t *pc, int *param_get)
{
	int t_reg_value = *(tab + ((pc->idx + 2) % MEM_SIZE));

	if (parameters[0] == T_REG) {
		printf("DEBUG T REG VALUE : %d\n", t_reg_value);
		*param_get = 3;
		return (t_reg_value >= 1 && t_reg_value <= 16 ?
		t_reg_value : -1);
	} else if (parameters[0] == T_DIR) {
		*param_get = 6;
		return (get_int(tab + ((pc->idx + 2) % MEM_SIZE)));
	} if (parameters[0] == T_IND) {
		*param_get = 4;
		return (get_short_int(tab + ((pc->idx + 2) % MEM_SIZE)));
	}
	return (0);
}

int parameters_two(int *parameters, byte *tab, pc_t *pc, int param_get)
{
	int t_reg_value = *(tab + ((pc->idx + param_get) % MEM_SIZE));

	if (parameters[1] == T_REG)
		return (t_reg_value >= 1 && t_reg_value <= 16 ?
		t_reg_value : -1);
	else if (parameters[1] == T_DIR)
		return (get_int(tab + ((pc->idx + param_get) % MEM_SIZE)));
	if (parameters[1] == T_IND)
		return (get_short_int(tab + ((pc->idx + param_get) % MEM_SIZE)));
	return (0);
}

int operate_and(champ_t *champ, pc_t *pc, byte *tab)
{
	printf("lol\n");
	int *parameters = detect_parameters(*(tab
	+ ((pc->idx + 1) % MEM_SIZE)));
	int *all_value = malloc(sizeof(int) + 3);
	int param_get = 0;

	if (check_parameters(parameters) == 84) {
		assign_champ_carry_false(champ, pc);
		printf("lol\n");
		return (1);
	}
	all_value[0] = parameters_zero(parameters, tab, pc, &param_get);
	all_value[1] = parameters_two(parameters, tab, pc, param_get);
	all_value[2] = compute_bytes_read(champ, pc, parameters) - 1;
	printf("%d && %d && %d --> result : %d\n", all_value[0], all_value[1], all_value[2], all_value[0] & all_value[1]);
	if (assign_to_last_register(all_value, champ, pc) == 84)
		assign_champ_carry_false(champ, pc);
	return (0);
}