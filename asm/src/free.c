/*
** EPITECH PROJECT, 2017
** asm
** File description:
** free.c created: 11/03/18 17:41
*/

#include <asm.h>
#include <my.h>

void free_label_list(void)
{
	label_t **a = get_label_list();
	label_t *tmp = *a;
	label_t *old_tmp = NULL;

	free(a);
	if (!tmp)
		return;
	for (; tmp; tmp = tmp->next) {
		if (old_tmp)
			free(old_tmp);
		old_tmp = tmp;
	}
	free(old_tmp);
}

void free_instruction(instruction_t *op)
{
	free(op->args_types);
	free(op->args);
	free(op);
}

void free_operation_list(void)
{
	instruction_t **op = get_instructions();
	instruction_t *tmp = *op;
	instruction_t *old_tmp = NULL;

	free(op);
	if (!tmp)
		return;
	for (; tmp; tmp = tmp->next){
		if (old_tmp)
			free_instruction(old_tmp);
		old_tmp = tmp;
	}
	free_instruction(old_tmp);
}

void free_cmd_data(void)
{
	cmd_data *a = get_cmd_data();

	free(a->name);
	free(a->description);
	free(a);
}

void free_content(void)
{
	free_label_list();
	free_operation_list();
	free_cmd_data();
	free(is_label_turn());
}