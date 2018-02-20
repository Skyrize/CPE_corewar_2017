/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** NULL
*/

#include "vm.h"

int reverse_int(int nb)
{
	union number number;
	char tmp;

	number.nbr = nb;
	tmp = number.str[0];
	number.str[0] = number.str[3];
	number.str[3] = tmp;
	tmp = number.str[1];
	number.str[1] = number.str[2];
	number.str[2] = tmp;
	return (number.nbr);
}