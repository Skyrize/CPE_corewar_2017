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

int *fill_parameters_and_instruct(int *parameters)
{
	int *param = malloc(sizeof(int) * 5);

	param[0] = parameters[0];
	param[1] = parameters[1];
	param[2] = parameters[2];
	param[3] = 0;
	return (param);
}

int check_parameters_and_instruct(int *param, champ_t *champ, pc_t *pc,
int func)
{
	if ((check_parameters(param) == 84) && func == 0) {
		assign_champ_carry_false(champ, pc);
		return (1);
	}
	if ((param[0] == -1 || param[1] == -1 || param[2] == -1)
	&& func == 1) {
		assign_champ_carry_false(champ, pc);
		return (1);
	}
	return (0);
}