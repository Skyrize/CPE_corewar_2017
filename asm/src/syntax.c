/*
** EPITECH PROJECT, 2017
** asm
** File description:
** syntax.c created: 12/02/18 19:19
*/

#include <stdbool.h>
#include <asm.h>
#include <my.h>
#include <op.h>

bool is_label(char **words)
{
	int i = 0;

	for (; words[0][i]; i++);
	i--;
	if (words[0][i] == LABEL_CHAR)
		return (true);
	return (false);
}

void remove_commentary(char *line)
{
	for (int i = 0; line[i]; i++)
		if (line[i] == COMMENT_CHAR)
			line[i] = '\0';
}

bool is_valid_args(char **words, int id, uint begin_idx)
{
	args_type_t *types = op_tab[id].type;
	uint args_nbr = (uint) op_tab[id].nbr_args;

	if (my_array_length((void **)words) - begin_idx - 1 != args_nbr) {
		my_putstr("Bad argument number\n");
		return (false);
	}
	return (true);
}

bool check_unknown_line(char **words)
{
	if (my_strcmp(words[0], NAME_CMD_STRING) == 0)
		return (true);
	if (my_strcmp(words[0], COMMENT_CMD_STRING) == 0)
		return (true);
	return (false);
}

bool is_line_valid(char *line)
{
	char **words;
	int id = -1;
	uint begin_idx = 0;

	remove_commentary(line);
	clean_str_asm(&line);
	if (my_strlen(line) == 0)
		return (true);
	words = my_split(line, ' ');
	scan_line_for_labels(words);
	(is_label(words)) ? (begin_idx ++) : (0);
	if (my_array_length((void **) words) <= begin_idx)
		return (true);
	for (int i = 0; op_tab[i].mnemonique; i++)
		if (my_strcmp(op_tab[i].mnemonique, words[begin_idx]) == 0)
			id = i;
	if (id == -1) {
		if (is_valid_cmd(words))
			return (true);
		my_putstr("bad line\n");
		return (false);
	}
	is_valid_args(words, id, begin_idx);
	process_instruction_line(words);
}