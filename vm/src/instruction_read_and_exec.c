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

	for (; op_tab[i].code != instruction; i++);
	return (i);
}

int execute_instruct(pc_t *pc, char *vm, champ_t *champ)
{
	int op = get_op(vm[pc->idx]);
	byte **tab;

	check_functions_args_and_bytes(op_tab[op], pc, vm);
	//op_tab[op].fptr(champ, pc, tab);
	pc->countdown = op_tab[op].nbr_cycles;
	return (0);
}
