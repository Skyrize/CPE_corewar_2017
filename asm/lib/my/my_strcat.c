/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** concatenate a string
*/

#include <stdlib.h>

int	strcat_len(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i += 1);
	return (i);
}

char	*my_strcat(char *dest, char const *src)
{
	int	dest_len = strcat_len(dest);
	int	i;

	for (i = 0; src[i] != '\0'; i += 1) {
		dest[dest_len + i] = src[i];
	}
	return (dest);
}

char 	*my_str_append(char *stra, char *strb)
{
	int	len_a = strcat_len(stra);
	int	len_b = strcat_len(strb);
	char	*res = malloc(sizeof(char) * (len_a + len_b + 1));
	int	i = 0;
	int	j = 0;

	for (; i < len_a; i += 1) {
		res[i] = stra[i];
	}
	for (; j < len_b; j += 1) {
		res[i + j] = strb[j];
	}
	res[i + j] = '\0';
	return (res);
}