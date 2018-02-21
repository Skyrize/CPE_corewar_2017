/*
** EPITECH PROJECT, 2018
** VM Corewar
** File description:
** NULL
*/

#include "vm.h"

void fill_memory_zone_owner(champ_t *champ, memory_t *vm, int zone)
{
	for (int i = zone; i < champ->size + zone; i++)
		vm->owner[i] = champ->program_number;
}

void memory_allocation_to_champs(memory_t *vm, champ_t *champs, int nb_champs)
{
	int zone = 0;

	for (int i = 0; i < MEM_SIZE; i++)
		vm->owner[i] = 0;
	for (int i = 0; i < nb_champs; i++) {
		zone = MEM_SIZE * i / nb_champs;
		fill_memory_zone_owner(champs, vm, MEM_SIZE * i / nb_champs);
		champs = champs->next;
	}
	my_putchar('\n');
}