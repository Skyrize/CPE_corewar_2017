/*
** EPITECH PROJECT, 2017
** vm
** File description:
** (enter)
*/

#include "vm.h"

int check_champs_live(champ_t *champs)
{
	unsigned int i = 0;
	champ_t *tmp = champs;

	while (tmp) {
		if (tmp->alive == 1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}