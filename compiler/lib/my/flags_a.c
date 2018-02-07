/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Main file of the function my_printf
*/

#include "my.h"
#include <stdarg.h>

void	flag_c(va_list list, char *a)
{
	char c = (char) va_arg(list, int);
	int i = 0;
	int num = my_getnbr(a);

	my_putstr(a);
	if (num && num >= 0) {
		for (; i < num - 1; i += 1)
			my_putchar(' ');
		my_putchar(c);
	} else {
		my_putchar(c);
		for (; i < (-num) - 1; i += 1)
			my_putchar(' ');
	}
}

void	flag_s(va_list list, char *a)
{
	char *s = va_arg(list, char*);
	int s_len = my_strlen(s);
	int i = 0;
	int num = my_getnbr(a);

	if (num && num >= 0) {
		for (; i < num - s_len; i += 1)
			my_putchar(' ');
		my_putstr(s);
	} else {
		my_putstr(s);
		for (; i < (-num) - s_len; i += 1)
			my_putchar(' ');
	}
}

void	flag_d(va_list list, char *a)
{
	int d = va_arg(list, int);

	if (my_contains("+", a))
		(d >= 0) ? my_putchar('+') : (a = a);
	else
		(my_contains(" ", a) && d >= 0) ? my_putchar(' ') : (a = a);
	my_put_nbr(d);
}

void	flag_pc(va_list list, char *a)
{
	(void)list;
	(void)a;
	my_putchar('%');
}

void	flag_ld(va_list list, char *a)
{
	long ld = va_arg(list, long);

	(void)a;
	my_put_long(ld);
}