/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copy n char from a string to another
*/

#include "my.h"

char	*my_strncpy(char *dest, char const *src, int n)
{
	int	i = 0;
	int	src_len = my_strlen(src);

	for (i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	if (src_len > i) {
		dest[i] = '\0';
	}
	return (dest);
}
