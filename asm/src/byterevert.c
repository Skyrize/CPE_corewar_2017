/*
** EPITECH PROJECT, 2017
** asm
** File description:
** byterevert.c created: 27/02/18 19:03
*/

#include <asm.h>
#include <limits.h>

int revert_int(int nbr)
{
	union four_bytes_union a;
	char tmp_a;
	char tmp_b;

	a.i = nbr;
	tmp_a = a.str[0];
	tmp_b = a.str[3];
	a.str[0] = tmp_b;
	a.str[3] = tmp_a;
	tmp_a = a.str[1];
	tmp_b = a.str[2];
	a.str[1] = tmp_b;
	a.str[2] = tmp_a;
	return (a.i);
}

short revert_short(short nbr)
{
	union two_bytes_union a;
	char tmp_a;
	char tmp_b;

	a.i = nbr;
	tmp_a = a.str[0];
	tmp_b = a.str[1];
	a.str[0] = tmp_b;
	a.str[1] = tmp_a;
	return (a.i);
}

unsigned int get_uint(char const *nbr)
{
	unsigned long number = 0;
	int is_neg = 1;
	int i = 0;

	for (; nbr[i] == '-' || nbr[i] == '+'; i++)
		(nbr[i] == '-' ? is_neg *= -1 : 0);
	for (; nbr[i] >= '0' && nbr[i] <= '9'; i++)
		number = number * 10 + nbr[i] - 48;
	(number > UINT_MAX || number < 0) ? number = 0 : number;
	return ((unsigned int)(is_neg == -1 ? number *= -1 : number));
}