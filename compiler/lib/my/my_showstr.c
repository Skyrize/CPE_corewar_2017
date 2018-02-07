/*
** EPITECH PROJECT, 2017
** my_showstr
** File description:
** return 0 if not printable, print it else
*/

#include "my.h"

int	my_showstr(char const *str)
{
	int i = 0;

	while (str[i]) {
		if (my_isprintable(str[i]))
			my_putchar(str[i]);
		else {
			my_putchar('\\');
			(str[i] < 16) ? (my_putchar('0')) : (i = i);
			my_putnbr_base(str[i], "0123456789abcdef");
		}
		i += 1;
	}
	return (0);
}
