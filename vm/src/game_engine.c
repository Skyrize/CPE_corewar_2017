/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"
#include <stdint.h>

// void execute_pc(char *vm, pc_t *pc, champ_t *champ, int *nbr_live)
// {
// 	pc_t *tmp = pc;

// 	while (tmp) {
// 		if (tmp->countdown == 0) {
// 			tmp->idx += execute_instruct(tmp, vm, champ, nbr_live);
// 		} else
// 			tmp->countdown--;
// 		tmp = tmp->next;
// 	}
// }

// void execute_champs_pc(char *vm, champ_t *champs, int *nbr_live)
// {
// 	champ_t *tmp = champs;

// 	while (tmp) {
// 		execute_pc(vm, tmp->pc, champs, nbr_live);
// 		tmp = tmp->next;
// 	}
// }

// void start_cycle_game(char *vm, champ_t *champs)
// {
// 	unsigned int cycle_to_die = CYCLE_TO_DIE;
// 	unsigned int i = cycle_to_die;
// 	unsigned int nbr_live = 0;

// 	while (cycle_to_die > 0 || check_champs_live(champs) != 1) {
// 		execute_champs_pc(vm, champs, &nbr_live);
// 		if (i-- == 0 || nbr_live >= NBR_LIVE) {
// 			cycle_to_die -= CYCLE_DELTA;
// 			i = cycle_to_die;
// 		}
// 		my_printf("%d\n", i);
// 	}
// }
