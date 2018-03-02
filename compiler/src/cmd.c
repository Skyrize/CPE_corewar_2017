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
		words[len - 1][my_strlen(words[len - 1]) - 1] == '"')
		return (true);
	return (false);
}

bool is_valid_cmd(char **words)
{
	if (check_unknown_line(words) && is_cmd_valid(words))
		return (true);
	my_putstr("bad formatting on command line\n");
	return (false);
}