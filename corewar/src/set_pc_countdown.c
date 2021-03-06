/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** set_pc_countdown.c
*/

#include "vm.h"

void set_pc_countdown(pc_t *pc, byte *vm)
{
	int tab_idx = 0;

	if (pc->idx < 0)
		pc->idx += MEM_SIZE;
	tab_idx = get_op(vm[pc->idx]);
	if (tab_idx == 84) {
		pc->countdown = 0;
		return;
	}
	pc->countdown = op_tab[tab_idx].nbr_cycles;
}

void set_all_champs_pc_countdown(champ_t *champs, memory_t *vm)
{
	while (champs) {
		set_pc_countdown(champs->pc, vm->vm);
		champs = champs->next;
	}
}