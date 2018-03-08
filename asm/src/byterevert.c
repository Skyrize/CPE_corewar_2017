/*
** EPITECH PROJECT, 2017
** asm
** File description:
** byterevert.c created: 27/02/18 19:03
*/

#include <asm.h>

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