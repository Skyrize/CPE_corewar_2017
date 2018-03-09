/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Main file of the function my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <printf.h>

const operation_t oper_array[] = {
	{'c', flag_c},
	{'s', flag_s},
	{'d', flag_d},
	{'i', flag_d},
	{'u', flag_u},
	{'%', flag_pc},
	{'p', flag_p},
	{'x', flag_x},
	{'o', flag_o},
	{'X', flag_xx},
	{'b', flag_b},
	{'S', flag_ss},
	{'\0', NULL}
};

void get_operator(const char *str, int *i)
{
	char *ops = "0123456789. +-#*";
	char *tempchar = my_strdup("a");

	for (; str[*i]; *i += 1) {
		tempchar[0] = str[*i];
		if (!my_contains(ops, tempchar))
			break;
	}
	free(tempchar);
}

char *my_cutstr(const char *str, int a, int b)
{
	int i = 0;
	char *res = malloc(sizeof(char) * (b - a + 1));

	for (; str[a + i] && a + i < b; i += 1) {
		res[i] = str[a + i];
	}
	res[i] = '\0';
	return (res);
}

int execute_spe_func(const char c, va_list list, int *arr, char *inter)
{
	int validate = 0;

	if (arr[0] && c == 'd') {
		flag_ld(list, inter);
		validate = 1;
	} else if (arr[1] && c == 'd') {
		flag_d(list, inter);
		validate = 1;
	}
	return (validate);
}

void execute_func(const char *c, va_list list, int *i, char *inter)
{
	int j = 0;
	int val = 0;
	int *arr = malloc(sizeof(int) * 3);
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;

	(c[0] == 'l') ? arr[0] = 1 : (c[0] == 'h') ? arr[1] = 1 : (j = j);
	if (arr[0] || arr[1]) {
		*i += 1;
		val = execute_spe_func(c[1], list, arr, inter);
		if (val)
			return;
	}
	for (; oper_array[j].c; j += 1)
		if (oper_array[j].c == *c) {
			oper_array[j].operation(list, inter);
			val = 1;
		}
	(!val) ? flag_pc(list, inter) : (j = j);
}

int my_printf(char const *format, ...)
{
	va_list list;
	int i;
	int tmp;
	char *operator;

	va_start(list, format);
	for (i = 0; format[i]; i += 1) {
		if (format[i] != '%')
			my_putchar(format[i]);
		else {
			i += 1;
			tmp = i;
			get_operator(format, &i);
			operator = my_cutstr(format, tmp, i);
			execute_func(&format[i], list, &i, operator);
		}
	}
	va_end(list);
	return (0);
}