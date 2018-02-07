/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** return the number from a string
*/

#include <limits.h>

int	my_getnbr(char const *nbr)
{
	long number = 0;
	int is_neg = 1;
	int i = 0;

	for (; nbr[i] == '-' || nbr[i] == '+'; i++)
		(nbr[i] == '-' ? is_neg *= -1 : 0);
	for (; nbr[i] >= '0' && nbr[i] <= '9'; i++)
		number = number * 10 + nbr[i] - 48;
	(number > INT_MAX || number < INT_MIN) ? number = 0 : number;
	return ((is_neg == -1 ? number *= -1 : number));
}
