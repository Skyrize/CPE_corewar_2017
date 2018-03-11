/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

void add_pc_fork(pc_t *pc, int fork_value, byte *tab)
{
	pc_t *tmp = malloc(sizeof(*tmp));

	tmp->idx = (pc->idx + fork_value % IDX_MOD) % MEM_SIZE;
	//my_printf("debug : %d \n", tmp->idx);
	tmp->champ_owner = pc->champ_owner;
	tmp->next = NULL;
	while (pc->next)
		pc = pc->next;
	pc->next = tmp;
	set_pc_countdown(pc->next, tab);
}

int operate_fork(champ_t *champs, pc_t* pc, byte *tab)
{
	// my_printf("debug : %d \n", pc->idx);
	int fork_value = get_short_int(tab + ((pc->idx + 1) % MEM_SIZE));

	add_pc_fork(pc, fork_value, tab);
	return (2);
}