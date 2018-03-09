/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void add_pc(pc_t *pc, int fork_value, byte *tab)
{
	pc_t *tmp;

	tmp->idx = (pc->idx + fork_value % IDX_MOD) % MEM_SIZE;
	tmp->champ_owner = pc->champ_owner;
	tmp->next = NULL;
	pc->next = tmp;
	set_pc_countdown(pc->next, tab);
}

int operate_fork(champ_t *champs, pc_t* pc, byte *tab)
{
	int fork_value = get_int(tab + ((pc->idx + 1) % MEM_SIZE));

	add_pc(pc, fork_value, tab);
	return (4);
}