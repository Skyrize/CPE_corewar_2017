/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** concatenate after n
*/

#include "my.h"

char	*my_strncat(char *dest, const char *src, int n)
{
	int	dest_len = my_strlen(dest);
	int	i;

	for (i = 0; i < n && src[i] != '\0'; i += 1)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
