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

int execute_instruct(pc_t *pc, memory_t *vm, champ_t *champ)
{
	int op = get_op(vm->memory[tmp->idx]);
	byte **tab;

	//op_tab[op].fptr(champ, pc, tab);
	pc->countdown = op_tab[op].nbr_cycles;
	return ();
}
