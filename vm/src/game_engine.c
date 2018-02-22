/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"
#include <stdint.h>

void execute_pc(memory_t *vm, pc_t *pc)
{
	pc_t *tmp = pc;

	while (tmp) {
		if (tmp->countdown == 0) {
			tmp->idx += execute_instruct(tmp, vm);
		} else
			tmp->countdown--;
		tmp = tmp->next;
	}
}

void execute_champs_pc(memory_t *vm, champ_t *champs)
{
	champ_t *tmp = champs;

	while (tmp) {
		execute_pc(vm, tmp->pc);
		tmp = tmp->next;
	}
}

void start_cycle_game(memory_t *vm, champ_t *champs)
{
	unsigned int cycle_to_die = CYCLE_TO_DIE;
	unsigned int i = cycle_to_die;

	while (cycle_to_die > 0 || check_champs_live(champs) != 1) {
		execute_champs_pc(vm, champs);
		if (i-- == 0) {
			cycle_to_die -= CYCLE_DELTA;
			i = cycle_to_die;
		}
		printf("%d\n", i);
	}
}
