/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "vm.h"

int operate_lfork(champ_t *champs, pc_t* pc, byte *tab)
{
	int fork_value = get_int(tab + pc->idx + 1);

	add_pc(pc, fork_value, tab);
	return (2);
}