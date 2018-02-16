/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** my_split.c
*/

#include <stdlib.h>

int get_group_len(char *str, char sp, int pos)
{
	int i = 0;
	int npos = 0;
	int len = 0;

	for (; str[i] && pos != npos; i += 1) {
		(str[i] == sp) ? (npos += 1) : 1;
	}
	for (; str[i] && str[i] != sp; i += 1)
		len += 1;
	return (len);
}

int get_group_nbr(char *str, char sp)
{
	int i = 0;
	int ret = 1;

	if (!str[0])
		return (0);
	for (; str[i + 1]; i += 1)
		ret += (str[i] == sp && str[i + 1] != sp) ? 1 : 0;
	return (ret);
}

void fill_grps(char *str, char sp, char **ret)
{
	int pos = 0;
	int i = 0;
	int posi = 0;

	for (; str[i]; i += 1) {
		if (str[i] == sp && str[i + 1] != sp) {
			ret[pos][posi] = '\0';
			pos += 1;
			posi = 0;
			continue;
		}
		if (str[i] != sp) {
			ret[pos][posi] = str[i];
			posi += 1;
		}
	}
	ret[pos + 1] = NULL;
}

char **my_split(char *str, char sp)
{
	int grp_nbr = get_group_nbr(str, sp);
	char **ret = malloc(sizeof(char *) * (grp_nbr + 2));
	int i = 0;
	int len;

	for (; i < grp_nbr; i += 1) {
		len = get_group_len(str, sp, i);
		ret[i] = malloc(sizeof(char) * (len + 1));
		for (int j = 0; j < (len + 1); j += 1) {
			ret[i][j] = '\0';
		}
	}
	fill_grps(str, sp, ret);
	return (ret);
}

int my_array_length(void **arr)
{
	int i = 0;

	for (; arr[i]; i += 1);
	return (i);
}
