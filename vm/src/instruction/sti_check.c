/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int check_reg_sti(int *param, int first, int second, int third)
{
	if ((param[0] == T_REG && (first < 1 || first > 16)) ||
	(param[1] == T_REG && (second < 1 || second > 16)) ||
	(param[2] == T_REG && (third < 1 || third > 16)))
		return (84);
	return (0);
}

int how_much_read_sti(int *parameters)
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