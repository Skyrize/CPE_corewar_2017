/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"
#include <stdint.h>

void execute_champs_pc(champ_t *champs)
{
	champ_t *tmp = champs;

	while (tmp) {
		tmp = tmp->next;
	}
}

void start_cycle_game(memory_t *vm, champ_t *champs)
{
	unsigned int cycle_to_die = CYCLE_TO_DIE;
	unsigned int i = cycle_to_die;

	while (cycle_to_die > 0) {
		execute_champs_pc(champs);
		if (i-- == 0) {
			cycle_to_die -= CYCLE_DELTA;
			i = cycle_to_die;
		}
		printf("%d\n", i);
	}
}
