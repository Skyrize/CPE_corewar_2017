/*
** EPITECH PROJECT, 2017
** asm
** File description:
** op_args.c created: 07/03/18 15:17
*/

#include <asm.h>
#include <stdlib.h>
#include <my.h>

args_type_t *get_args_types(char **words)
{
	byte args_nbr = 0;
	args_type_t *res = NULL;

	args_nbr = op_tab[get_fnc_idx(words[0])].nbr_args;
	res = malloc(sizeof(*res) * args_nbr + 1);
	for (int i = 0; i < args_nbr; i++) {
		if (words[i + 1][0] == 'r')
			res[i] = T_REG;
		else if (words[i + 1][0] == DIRECT_CHAR)
			res[i] = T_DIR;
		else
			res[i] = T_IND;
	}
	res[args_nbr] = '\0';
	return (res);
}

byte get_args_nbr(char **words)
{
	byte args_nbr = 0;

	if (!is_valid_cmd(words))
		return -1;
	words = get_words_without_label(words);
	args_nbr = op_tab[get_fnc_idx(words[0])].nbr_args;
	return (args_nbr);
}

instruction_t **get_instructions(void)
{
	static instruction_t **ret = NULL;

	if (ret == NULL) {
		ret = malloc(sizeof(*ret));
		*ret = NULL;
	}
	return (ret);
}

bool is_there_a_command(char **words)
{
	int len = my_array_length((void **)words);
	int fnc_idx = 0;

	if (len < 2 || len > 6 || words[0][0] == '.')
		return (false);
	if (words[0][my_strlen(words[0]) - 1] == LABEL_CHAR)
		fnc_idx = get_fnc_idx(words[1]);
	else
		fnc_idx = get_fnc_idx(words[0]);
	return ((fnc_idx != -1) ? true : false);
}

void process_instruction_line(char **words)
{
	if (!is_there_a_command(words))
		return;
	words = get_words_without_label(words);
	add_operation_to_list(create_operation(words));
}