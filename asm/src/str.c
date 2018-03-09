/*
** EPITECH PROJECT, 2017
** asm
** File description:
** str.c created: 16/02/18 17:25
*/

#include <asm.h>
#include <op.h>

char *comma_to_spaces(char *line)
{
	for (int i = 0; line[i]; i++)
		if (line[i] == SEPARATOR_CHAR)
			line[i] = ' ';
	return (line);
}

char *tab_to_spaces(char *line)
{
	for (int i = 0; line[i]; i++)
		if (line[i] == '\t')
			line[i] = ' ';
	return (line);
}

char *remove_start_line(char *line)
{
	int i = 0;

	for (; line[i] == ' '; i++);
	line = &line[i];
	return (line);
}

void clean_str_asm(char **line)
{
	comma_to_spaces(*line);
	tab_to_spaces(*line);
	*line = remove_start_line(*line);
}