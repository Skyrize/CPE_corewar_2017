/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"
#include <stdint.h>

void start_cycle_game(char *vm, champ_t *champs)
{
	champ_t *tmp = champs;
	unsigned int cycle_to_die = CYCLE_TO_DIE;
	unsigned int i = cycle_to_die;

	while (cycle_to_die > 0) {
		if (i-- == 0) {
			cycle_to_die -= CYCLE_DELTA;
			i = cycle_to_die;
		}
		my_printf("%d\n", i);
	}
}
