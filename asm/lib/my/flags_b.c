/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** functions of flags
*/

#include "my.h"
#include <stdarg.h>

void	flag_p(va_list list, char *a)
{
	long p = va_arg(list, long);

	(void)a;
	my_putstr("0x");
	my_putlong_base(p, "0123456789abcdef");
}

void	flag_x(va_list list, char *a)
{
	int nb = va_arg(list, int);

	(my_contains("#", a)) ? (void)my_putstr("0x") : ((void)(a = a));
	my_putnbr_base(nb, "0123456789abcdef");
}

void	flag_o(va_list list, char *a)
{
	int nb = va_arg(list, int);

	(my_contains("#", a)) ? (void)my_putstr("0") : ((void)(a = a));
	my_putnbr_base(nb, "01234567");
}

void	flag_u(va_list list, char *a)
{
	unsigned int nb = (unsigned int) va_arg(list, int);

	(void)a;
	my_put_nbr(nb);
}

void	flag_xx(va_list list, char *a)
{
	int nb = va_arg(list, int);

	(my_contains("#", a)) ? (void)my_putstr("0x") : ((void)(a = a));
	my_putnbr_base(nb, "0123456789ABCDEF");
}