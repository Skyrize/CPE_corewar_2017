/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** operation for the %
*/

#include <stdarg.h>
#include "my.h"

void 	flag_b(va_list list, char *a)
{
	(void)a;
	unsigned int nb = (unsigned int) va_arg(list, int);

	my_putnbr_base(nb, "01");
}

void	flag_ss(va_list list, char *a)
{
	(void)a;
	char *c = va_arg(list, char *);
	my_showstr((const char *) c);
}