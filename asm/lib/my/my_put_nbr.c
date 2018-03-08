/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** print a number
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	if (nb < 10 && nb >= 0) {
		my_putchar(nb + 48);
		return (0);
	}
	if (nb == -2147483648) {
		my_put_nbr(-214);
		my_put_nbr(7483648);
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		my_put_nbr(-nb);
	} else if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_putchar((nb % 10) + 48);
	}
	return (0);
}

int	my_put_long(long nb)
{
	if (nb < 10 && nb >= 0) {
		my_putchar(nb + 48);
		return (0);
	}
	if (nb == -9223372036854775807) {
		my_putstr("-9223372036854775");
		my_putstr("808");
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		my_put_long(-nb);
	} else if (nb >= 10) {
		my_put_long(nb / 10);
		my_putchar((nb % 10) + 48);
	}
	return (0);
}