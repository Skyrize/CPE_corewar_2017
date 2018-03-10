/*
** EPITECH PROJECT, 2017
** asm
** File description:
** operation.c created: 06/03/18 15:21
*/

#include <asm.h>
#include <op.h>
#include <my.h>

char **get_words_without_label(char **words)
{
	if (is_label(words))
		return (&words[1]);
	return (words);
}

int get_fnc_idx(char *fnc_name)
{
	for (int i = 0; op_tab[i].mnemonique; i++)
		if (my_strcmp(op_tab[i].mnemonique, fnc_name) == 0)
			return (i);
	return (-1);
}

byte get_coding_byte(char **words)
{
	int command_idx = 0;

	words = get_words_without_label(words);
	command_idx = get_fnc_idx(words[0]);
	return (get_param_bytecode(words, op_tab[command_idx].nbr_args));
}

instruction_t *create_operation(char **words)
{
	instruction_t *instruction = malloc(sizeof(*instruction));

	words = get_words_without_label(words);
	instruction->coding_byte = get_coding_byte(words);
	instruction->instruction_code = op_tab[get_fnc_idx(words[0])].code;
	instruction->args_types = get_args_types(words);
	instruction->nbr_args = get_args_nbr(words);
	instruction->args = get_operation_args(words, instruction->args_types);
	instruction->next = NULL;
	return (instruction);
}

instruction_t *add_operation_to_list(instruction_t *instruction)
{
	instruction_t **root_addr = get_instructions();
	instruction_t *tmp = NULL;

	counter_b(compute_fnc_size(instruction));
	if (!(*root_addr)) {
		*root_addr = instruction;
		return (*root_addr);
	}
	tmp = *root_addr;
	for (; tmp->next; tmp = tmp->next);
	tmp->next = instruction;
	return (*root_addr);
}