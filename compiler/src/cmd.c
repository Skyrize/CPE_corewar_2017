/*
** EPITECH PROJECT, 2017
** asm
** File description:
** var_types.c created: 28/02/18 11:05
*/

#include <my.h>
#include <asm.h>

bool is_cmd_valid(char **words)
{
	int len = my_array_length((void **) words);

	if (len < 2)
		return (false);
	if (words[1][0] == '"' &&
		words[len - 1][my_strlen(words[len - 1]) - 1] == '"') {

		return (true);
	}
	return (false);
}

char *get_cmd_str(char *line)
{
	int i;
	int j;
	char *res;

	if (!is_valid_cmd(my_split(line, ' ')))
		return (NULL);
	for (i = 0; line[i] && line[i] != '"'; i++);
	i++;
	for (j = 0; line[i + j] && line[i + j] != '"'; j++);
	res = malloc(sizeof(char) * j + 1);
	for (j = 0; line[i + j] && line[i + j] != '"'; j++) {
		res[j] = line[i + j];
	}
	res[j] = '\0';
	return (res);
}

bool is_valid_cmd(char **words)
{
	if (check_unknown_line(words) && is_cmd_valid(words))
		return (true);
	my_putstr("bad formatting on command line\n");
	return (false);
}