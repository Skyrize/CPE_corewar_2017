/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** put a base number
*/

#include "my.h"

void	calcul_put_long(long nbr, int length, char const *base)
{
	long i = nbr / length;
	long j = nbr % length;

	if (nbr < 0) {
		my_putchar('-');
		calcul_put_long(-nbr, length, base);
	} else if (i >= length)
		calcul_put_long(i, length, base);
	else {
		switch (i)
		{
			case 0:
				break;
			default :
				my_putchar(base[i]);
		}
	}
	my_putchar(base[j]);
}

int	my_putlong_base(long nbr, char const *base)
{
	int lenght = my_strlen(base);

	calcul_put_long(nbr, lenght, base);
	return (0);
}
