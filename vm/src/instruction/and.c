/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"


typedef struct and_s {
	int registre_param_1;
	int dir_param_1;
	int ind_param_1;
	int registre_param_2;
	int dir_param_2;
	int ind_param_2;
	int last_register;
} and_t;

/*
**
**
** {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
**
**
*/
int check_parameters(int *parameters)
{
	if ((parameters[0] == 1 || parameters[0] == 2 || parameters[0] == 4)
	&& (parameters[1] == 1 || parameters[1] == 2 || parameters[1] == 4)
	&&(parameters[2] == 1))
		return (0);
	return (84);
}

and_t *init_struct_and(void)
{
	and_t *info_and = malloc(sizeof(and_t));

	info_and->registre_param_1 = 0;
	info_and->dir_param_1 = 0;
	info_and->ind_param_1 = 0;
	info_and->registre_param_2 = 0;
	info_and->dir_param_2 = 0;
	info_and->ind_param_2 = 0;
	info_and->last_register = 0;
	return (info_and);
}

void get_reg(and_t *info_rand, byte *tab,pc_t *pc, int param)
{
	int what_register = *(tab + pc->idx + 2);

	if (what_register < 1 && what_register > 16 && param == 0) {
		info_rand->registre_param_1 = 84;
		return;
	} else if (what_register < 1 && what_register > 16 && param == 1) {
		info_rand->registre_param_2 = 84;
		return;
	}
	if (what_register >= 1 && what_register <= 16 && param == 0)
		info_rand->registre_param_1 = what_register;
	else if (what_register >= 1 && what_register <= 16 && param == 1)
		info_rand->registre_param_2 = what_register;
}

void get_dir(and_t *info_rand, byte *tab,pc_t *pc, int param)
{
	int dir_value = get_int(tab + pc->idx + 2);

	if (param == 0)
		info_rand->dir_param_1 = dir_value;
	else if (param == 1)
		info_rand->dir_param_2 = dir_value;
}
void get_ind(and_t *info_rand, byte *tab, pc_t *pc, int param)
{
	int ind_value = get_short_int(tab + pc->idx + 2);

	if (param == 0)
		info_rand->ind_param_1 = ind_value;
	else if (param == 1)
		info_rand->ind_param_2 = ind_value;
}

void parameters_zero(and_t *info_and, int *parameters, byte *tab, pc_t *pc)
{
	if (parameters[0] == T_REG)
		get_reg(info_and, tab, pc, 0);
	else if (parameters[0] == T_DIR)
		get_dir(info_and, tab, pc, 0);
	if (parameters[0] == T_IND)
		get_ind(info_and, tab, pc, 0);
}

void parameters_two(and_t *info_and, int *parameters, byte *tab, pc_t *pc)
{
	if (parameters[1] == T_REG)
		get_reg(info_and, tab, pc, 1);
	else if (parameters[1] == T_DIR)
		get_dir(info_and, tab, pc, 1);
	if (parameters[1] == T_IND)
		get_ind(info_and, tab, pc, 1);
}


	//TODO : mettre à la norme
void parameters_three(and_t *info_and, int *parameters, byte *tab, pc_t *pc)
{
	int w_register = 0;

	(parameters[0] == T_REG
	&& parameters[1] == T_REG) ? w_register = *(tab + pc->idx + 2) : 0;
	(parameters[0] == T_REG
	&& parameters[1] == T_IND) ? w_register = *(tab + pc->idx + 3) : 0;
	(parameters[0] == T_REG
	&& parameters[1] == T_DIR) ? w_register = *(tab + pc->idx + 5) : 0;
	(parameters[0] == T_DIR
	&& parameters[1] == T_REG) ? w_register = *(tab + pc->idx + 5) : 0;
	(parameters[0] == T_DIR
	&& parameters[1] == T_IND) ? w_register = *(tab + pc->idx + 6) : 0;
	(parameters[0] == T_DIR
	&& parameters[1] == T_DIR) ? w_register = *(tab + pc->idx + 8) : 0;
	(parameters[0] == T_IND
	&& parameters[1] == T_REG) ? w_register = *(tab + pc->idx + 3) : 0;
	(parameters[0] == T_IND
	&& parameters[1] == T_IND) ? w_register = *(tab + pc->idx + 4) : 0;
	(parameters[0] == T_IND
	&& parameters[1] == T_DIR) ? w_register = *(tab + pc->idx + 6) : 0;
	if (w_register >= 1 && w_register <= 16)
		info_and->last_register = w_register;
	else
		info_and->last_register = 84;
}

//demander à lucas si la value get d'n IND ou d'un DIR peut être égale à 0 ?
int get_value_param_1(and_t *info_and, champ_t *champ)
{
	if (info_and->registre_param_1 == 84
	|| info_and->dir_param_1 == 84
	|| info_and->ind_param_1 == 84)
		return (84);
	if (info_and->registre_param_1 != 0 && info_and->registre_param_1 != 84)
		return (info_and->registre_param_1);
	if (info_and->dir_param_1 != 0 && info_and->dir_param_1 != 84)
		return (info_and->dir_param_1);
	if (info_and->ind_param_1 != 0 && info_and->ind_param_1 != 84)
		return (info_and->ind_param_1);
	return (0);
}

int get_value_param_2(and_t *info_and, champ_t *champ)
{
	if (info_and->registre_param_2 == 84
	|| info_and->dir_param_2 == 84
	|| info_and->ind_param_2 == 84)
		return (84);
	if (info_and->registre_param_2 != 0 && info_and->registre_param_2 != 84)
		return (info_and->registre_param_2);
	if (info_and->dir_param_2 != 0 && info_and->dir_param_2 != 84)
		return (info_and->dir_param_2);
	if (info_and->ind_param_2 != 0 && info_and->ind_param_2 != 84)
		return (info_and->ind_param_2);
}

int assign_to_last_register(and_t *info_and, champ_t *champ, pc_t *pc)
{
	int value_1 = get_value_param_1(info_and, champ);
	int value_2 = get_value_param_2(info_and, champ);

	if (value_1 == 84 || value_2 == 84)
		return (84);
	while (champ) {
		if (champ->program_number == pc->champ_owner) {
			champ->reg[info_and->last_register - 1] = value_1 & value_2;
			champ->carry = true;
		}
		champ = champ->next;
	}
	return (0);
}

int operate_and(champ_t *champ, pc_t *pc, byte *tab)
{
	int *parameters = detect_parameters(*(tab + pc->idx + 1));
	and_t *info_and = init_struct_and();

	if (check_parameters(parameters) == 84)
		return (1);
	parameters_zero(info_and, parameters, tab, pc);
	parameters_two(info_and, parameters, tab, pc);
	parameters_three(info_and, parameters, tab, pc);
	if (assign_to_last_register(info_and, champ, pc) == 84) {
		while (champ) {
			(champ->program_number == pc->champ_owner) ? champ->carry = false : 0;
			champ = champ->next;
		}
	}
}