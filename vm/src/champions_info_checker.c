/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"

int check_champs_live(memory_t *memory)
{              	 
	unsigned int i = 0;
	champ_t *tmp;

	while (memory->next) {
		if (memory->next->alive == 1)
			i++;
		else if (memory->next->next != NULL) {
			tmp = memory->next;
			memory->next = memory->next->next;
			free(tmp);
		} else {
			tmp = memory->next;
			memory->next = NULL;
			free(tmp);
		}
		memory = memory->next;
	}
	return (i);
}