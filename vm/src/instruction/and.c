/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

// int check_parameters(int *parameters)
// {
// 	if ((parameters[0] == 1 || parameters[0] == 2 || parameters[0] == 4)
// 	&& (parameters[1] == 1 || parameters[1] == 2 || parameters[1] == 4)
// 	&&(parameters[2] == 1))
// 		return (0);
// 	return (84);
// }

// int assign_to_last_register(int *all_value, champ_t *champ, pc_t *pc)
// {
// 	if (all_value[0] == -1 || all_value[2] < 1 || all_value[2] > 16)
// 		return (84);
// 	while (champ) {
// 		if (champ->program_number == pc->champ_owner) {
// 			printf("FINAL :\nregister : %d\nresult : %d\n",
// 			all_value[2] - 1, all_value[0] & all_value[1]);
// 			champ->reg[all_value[2] - 1] =
// 			all_value[0] & all_value[1];
// 			champ->carry = true;
// 		}
// 		champ = champ->next;
// 	}
// 	return (0);
// }

// int parameters_zero(int *parameters, byte *tab, pc_t *pc, champ_t *champ)
// {
// 	int t_reg_value = *(tab + ((pc->idx + 2) % MEM_SIZE));
// 	int get_num = 0;
// 	int new_num = 0;

// 	if (parameters[0] == T_REG) {
// 		parameters[3] = 3;
// 		return (t_reg_value >= 1 && t_reg_value <= 16 ?
// 		get_register_value(pc, champ, t_reg_value) : -1);
// 	} else if (parameters[0] == T_DIR) {
// 		parameters[3] = 6;
// 		return (get_int(tab + ((pc->idx + 2) % MEM_SIZE)));
// 	}
// 	if (parameters[0] == T_IND) {
// 		parameters[3] = 4;
// 		get_num = get_short_int(tab + ((pc->idx + 2) % MEM_SIZE));
// 		new_num = get_int(tab + ((pc->idx + (get_num))
// 		% MEM_SIZE));
// 		return (new_num);
// 	}
// 	return (0);
// }

// int parameters_two(int *parameters, byte *tab, pc_t *pc, champ_t *champ)
// {
// 	int t_reg_value = *(tab + ((pc->idx + parameters[3]) % MEM_SIZE));
// 	int get_num = 0;
// 	int new_num = 0;

// 	if (parameters[1] == T_REG)
// 		return (t_reg_value >= 1 && t_reg_value <= 16 ?
// 		get_register_value(pc, champ, t_reg_value) : -1);
// 	else if (parameters[1] == T_DIR) {
// 		return (get_int(tab + ((pc->idx + parameters[3]) % MEM_SIZE)));
// 	}
// 	if (parameters[1] == T_IND) {
// 		get_num = get_short_int(tab + ((pc->idx + parameters[3]) % MEM_SIZE));
// 		new_num = get_int(tab + ((pc->idx + (get_num))
// 		% MEM_SIZE));
// 		return (new_num);
// 	}
// 	return (0);
// }

// //VERIF : que lucas à pas mis 4 param possible pour le int* parameters
// int *fill_parameters(int *parameters)
// {
// 	int *param = malloc(sizeof(int) * 5);

// 	param[0] = parameters[0];
// 	param[1] = parameters[1];
// 	param[2] = parameters[2];
// 	param[3] = 0;
// 	return (param);
// }

// int lobby_check_parameters(int *param, champ_t *champ, pc_t *pc, int func)
// {
// 	if (check_parameters(param) == 84 && func == 0) {
// 		assign_champ_carry_false(champ, pc);
// 		return (1);
// 	}
// 	if (check_parameters(param) == 84 && func == 0) {
// 		assign_champ_carry_false(champ, pc);
// 		return (1);
// 	}
// }

// int operate_and(champ_t *champ, pc_t *pc, byte *tab)
// {
// 	int *parameters = detect_parameters(*(tab
// 	+ ((pc->idx + 1) % MEM_SIZE)));
// 	int *final_parameters = fill_parameters(parameters);
// 	int *all_value = malloc(sizeof(int) + 3);

// 	if (lobby_check_parameters(parameters, champ, pc) == 1)
// 		return (1);
// 	all_value[0] = parameters_zero(final_parameters, tab, pc, champ);
// 	all_value[1] = parameters_two(final_parameters, tab, pc, champ);
// 	all_value[2] = *(tab + ((pc->idx + compute_bytes_read(champ, pc, parameters) + 1)));
// 	compute_bytes_read(champ, pc, parameters));
// 	if (lobby_check_parameters(all_value, champ, pc) == 1)
// 		return (1);
// 	if (assign_to_last_register(all_value, champ, pc) == 84)
// 		assign_champ_carry_false(champ, pc);
// 	return (0);
// }