/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"

int get_op(byte instruction)
{
	int i = 0;

	if (instruction < 1 || instruction > 16)
		return (84);
	for (; op_tab[i].code != instruction; i++);
	return (i);
}

int execute_instruct(pc_t *pc, memory_t *vm, champ_t *champ)
{
	int op = get_op(vm->vm[pc->idx]);
	int ret = 0;

	if (op == 84)
		return (1);
	else if (op == 0)
		vm->nbr_live += 1;
	ret = op_tab[op].fptr(champ, pc, vm->vm);
	return (ret + 1);
}
