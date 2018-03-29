/*
** EPITECH PROJECT, 2017
** is_number
** File description:
** return 1 if number, 0 else
*/

#include <stdbool.h>

int my_is_digit(char c)
{
	if (c >= '0' && c <= '9') {
		return (1);
	}
	return (0);
}

bool is_number(char *str)
{
	for (int i = 0; str[i + 1]; i++)
		if (!my_is_digit(str[i + 1]))
			return (false);
	if (!my_is_digit(str[0]) && str[0] != '-')
		return (false);
	return (true);
}

int my_contains(char *s, char *cont)
{
	int i;
	int j;
	int ret = 0;

	for (i = 0; cont[i]; i += 1) {
		for (j = 0; s[j]; j += 1) {
			(cont[i] == s[j]) ? (ret = 1) : (ret = ret);
		}
	}
	return (ret);
}