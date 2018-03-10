/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "my.h"

int check_functions_args_and_bytes(op_t *op, pc_t *pc, char *vm)
{
	if (my_strcmp(op->mnemonique, "live") == 0
	|| my_strcmp(op->mnemonique, "lfork") == 0)
	if (my_strcmp(op->mnemonique, "zjmp") == 0
	|| my_strcmp(op->mnemonique, "fork") == 0)
	if (my_strcmp(op->mnemonique, "ldi") == 0)
	if (my_strcmp(op->mnemonique, "sti") == 0)
	return (0);
}
