/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void add_pc_lfork(pc_t *pc, int fork_value, byte *tab)
{
	pc_t *tmp = malloc(sizeof(*tmp));

	tmp->idx = (pc->idx + fork_value) % MEM_SIZE;
	tmp->champ_owner = pc->champ_owner;
	tmp->next = NULL;
	while (pc->next)
		pc = pc->next;
	pc->next = tmp;
	set_pc_countdown(pc->next, tab);
}

int operate_lfork(champ_t *champs, pc_t* pc, byte *tab)
{
	int fork_value = get_int(tab + ((pc->idx + 1) % MEM_SIZE));

	add_pc_lfork(pc, fork_value, tab);
	return (2);
}