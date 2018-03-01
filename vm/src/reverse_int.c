/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** reverse_int
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

int reverse_short_int(int nb)
{
	union short_number number;
	char tmp;

	number.nbr = nb;
	tmp = number.str[0];
	number.str[0] = number.str[1];
	number.str[1] = tmp;
	return (number.nbr);
}