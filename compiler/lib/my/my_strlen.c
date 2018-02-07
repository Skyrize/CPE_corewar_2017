/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** get the length of a string
*/

#include <stdlib.h>

int	my_strlen(char const *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i += 1);
	return (i);
}
