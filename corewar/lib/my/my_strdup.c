/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** allocate memory of a string
*/

#include <stdlib.h>

char	*my_strdup(char const *src)
{
	int	i;
	int	length;
	char	*ret;

	for (length = 0; src[length]; length += 1);
	ret = malloc(sizeof(char) * (length + 1));
	for (i = 0; src[i] != '\0'; i += 1) {
		ret[i] = src[i];
	}
	ret[i] = '\0';
	return (ret);
}
