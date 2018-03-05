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

	if (instruction == 0)
		return (84);
	for (; op_tab[i].code != instruction; i++);
	return (i);
}

int execute_instruct(pc_t *pc, memory_t *vm, champ_t *champ)
{
	int op = get_op(vm->vm[pc->idx]);
	int *parameters;
	int ret = 0;

	if (op == 84)
		return (1);
	parameters = detect_parameters(vm->vm[pc->idx + 1]);
	//ret = op_tab[op].fptr(champ, pc, vm->vm);
	pc->countdown = op_tab[op].nbr_cycles;
	return (ret + 1);
}
