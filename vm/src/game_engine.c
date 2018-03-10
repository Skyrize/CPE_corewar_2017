/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"
#include <stdint.h>

void execute_pc(memory_t *memory, pc_t *pc, champ_t *champ)
{
	pc_t *tmp = pc;

	while (tmp) {
		if (get_op(memory->vm[tmp->idx]) == 84)
			tmp->idx += 1;
		else if (tmp->countdown == 0) {
			tmp->idx += execute_instruct(tmp, memory, champ);
			set_pc_countdown(tmp, memory);
		} else
			tmp->countdown -= 1;
		if (tmp->idx > MEM_SIZE - 1)
			tmp->idx %= MEM_SIZE;
		tmp = tmp->next;
	}
}

void execute_champs_pc(memory_t *memory, champ_t *champs)
{
	champ_t *tmp = champs;

	while (tmp) {
		execute_pc(memory, tmp->pc, champs);
		tmp = tmp->next;
	}
}

int end_cycle(memory_t *memory, champ_t *champs, int *cycle_to_die, int *i)
{
	// my_printf("nbr live = %d\ni = %d\n", memory->nbr_live, *i);
	if ((*i)-- == 0 || memory->nbr_live >= NBR_LIVE) {
		*cycle_to_die -= CYCLE_DELTA;
		*i = *cycle_to_die;
		memory->nbr_live = 0;
		if (check_champs_live(champs) < 2)
			return (1);
	}
	return (0);
}

void end_game(memory_t *memory, champ_t *champs)
{
	if (memory->last_alive == 0)
		return;
	while (champs && champs->program_number != memory->last_alive)
		champs = champs->next;
	if (champs == NULL)
		return;
	my_printf(WIN, champs->program_number, champs->program_name);
}

void start_cycle_game(unsigned char *vm, champ_t *champs)
{
	int cycle_to_die = CYCLE_TO_DIE;
	unsigned int i = cycle_to_die;
	memory_t *memory = malloc(sizeof(*memory));

	memory->vm = vm;
	memory->nbr_live = 0;
	memory->next = champs;
	set_all_champs_pc_countdown(champs, memory);
	while (cycle_to_die > 0) {
		execute_champs_pc(memory, champs);
		if (end_cycle(memory, champs, &cycle_to_die, &i) == 1)
			break;
	}
	end_game(memory, champs);
}