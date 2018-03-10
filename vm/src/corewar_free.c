/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** orewar_free.
*/

#include "vm.h"

void free_champ_pc(pc_t *pc)
{
	pc_t *tmp;

	if (pc == NULL)
		return;
	while (pc) {
		tmp = pc;
		pc = pc->next;
		free(tmp);
	}
}

void corewar_free(memory_t *memory, champ_t *champs)
{
	champ_t *tmp;

	free(memory);
	while (champs) {
		tmp = champs;
		champs = champs->next;
		free(tmp->program_name);
		free_champ_pc(tmp->pc);
		free(tmp);
	}
}